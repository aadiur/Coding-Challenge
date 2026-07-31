#!/usr/bin/env python3
"""
Reads stats.json (written by LeetHub v2) and the topic tables already present
in README.md, then regenerates the difficulty pie chart + topic-wise bar
chart, writing them back into README.md between the markers:

<!--STATS:START-->
...
<!--STATS:END-->

Run this from the repo root:
    python3 scripts/update_readme_stats.py
"""

import json
import re
import urllib.parse
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
STATS_FILE = REPO_ROOT / "stats.json"
README_FILE = REPO_ROOT / "README.md"

START_MARKER = "<!--STATS:START-->"
END_MARKER = "<!--STATS:END-->"


def load_difficulty_counts():
    data = json.loads(STATS_FILE.read_text())
    leetcode = data.get("leetcode", {})
    easy = leetcode.get("easy", 0)
    medium = leetcode.get("medium", 0)
    hard = leetcode.get("hard", 0)
    solved = leetcode.get("solved", easy + medium + hard)
    return easy, medium, hard, solved


def load_topic_counts():
    """
    Parses '## <Topic Name>' headings in README.md and counts how many
    problem links appear in the table underneath each one, up until the
    next '## ' heading. Returns a list of (topic, count) sorted descending.
    """
    text = README_FILE.read_text()

    # Only look at the part of the README that LeetHub generates
    # (starts at '# LeetCode Topics')
    marker = "# LeetCode Topics"
    idx = text.find(marker)
    if idx == -1:
        return []
    text = text[idx:]

    sections = re.split(r"\n## ", text)
    counts = []
    for section in sections[1:]:
        lines = section.splitlines()
        topic = lines[0].strip()
        # skip the '[#anchor](#anchor)' line under each heading if present
        body = "\n".join(lines[1:])
        # count markdown links that point to a problem folder, e.g.
        # [0001-two-sum](.../tree/master/0001-two-sum)
        links = re.findall(r"\[\d{4}-[a-z0-9-]+\]\(", body)
        if links:
            counts.append((topic, len(links)))

    counts.sort(key=lambda x: x[1], reverse=True)
    return counts


def build_pie_url(easy, medium, hard):
    config = {
        "type": "pie",
        "data": {
            "labels": ["Easy", "Medium", "Hard"],
            "datasets": [{
                "data": [easy, medium, hard],
                "backgroundColor": ["#00b8a3", "#ffc01e", "#ff375f"],
            }],
        },
        "options": {
            "plugins": {
                "legend": {"labels": {"fontColor": "#e9d5ff", "fontSize": 14}},
                "title": {
                    "display": True,
                    "text": "Difficulty Breakdown",
                    "fontColor": "#e9d5ff",
                    "fontSize": 16,
                },
            }
        },
    }
    return _quickchart_url(config, 420, 300)


def build_bar_url(topic_counts, top_n=10):
    top = topic_counts[:top_n]
    labels = [t for t, _ in top]
    values = [c for _, c in top]
    config = {
        "type": "horizontalBar",
        "data": {
            "labels": labels,
            "datasets": [{
                "label": "Problems",
                "data": values,
                "backgroundColor": "#8b5cf6",
            }],
        },
        "options": {
            "legend": {"display": False},
            "title": {
                "display": True,
                "text": "Topic-wise Distribution",
                "fontColor": "#e9d5ff",
                "fontSize": 16,
            },
            "scales": {
                "xAxes": [{
                    "ticks": {"fontColor": "#e9d5ff", "beginAtZero": True},
                    "gridLines": {"color": "#333"},
                }],
                "yAxes": [{
                    "ticks": {"fontColor": "#e9d5ff"},
                    "gridLines": {"color": "#333"},
                }],
            },
        },
    }
    return _quickchart_url(config, 480, 360)


def _quickchart_url(config, w, h, bg="0d0221"):
    q = {
        "c": json.dumps(config),
        "w": str(w),
        "h": str(h),
        "bkg": "#" + bg,
        "format": "png",
    }
    return "https://quickchart.io/chart?" + urllib.parse.urlencode(q)


def build_stats_block(easy, medium, hard, solved, topic_counts):
    pie_url = build_pie_url(easy, medium, hard)
    bar_url = build_bar_url(topic_counts)

    return f"""{START_MARKER}
<div align="center">

![Total Solved](https://img.shields.io/badge/Total%20Solved-{solved}-6d28d9?style=for-the-badge)
![Easy](https://img.shields.io/badge/Easy-{easy}-00b8a3?style=for-the-badge)
![Medium](https://img.shields.io/badge/Medium-{medium}-ffc01e?style=for-the-badge)
![Hard](https://img.shields.io/badge/Hard-{hard}-ff375f?style=for-the-badge)

<br/>

<img src="{pie_url}" width="45%"/>
<img src="{bar_url}" width="50%"/>

</div>
{END_MARKER}"""


def update_readme(new_block):
    text = README_FILE.read_text()
    if START_MARKER in text and END_MARKER in text:
        pattern = re.compile(
            re.escape(START_MARKER) + r".*?" + re.escape(END_MARKER),
            re.DOTALL,
        )
        new_text = pattern.sub(new_block, text)
    else:
        # markers not found yet — insert right after the first '#' title line
        lines = text.splitlines()
        insert_at = 1 if lines and lines[0].startswith("#") else 0
        lines[insert_at:insert_at] = ["", new_block, ""]
        new_text = "\n".join(lines)

    if new_text != text:
        README_FILE.write_text(new_text)
        print("README.md updated.")
    else:
        print("No changes needed.")


def main():
    easy, medium, hard, solved = load_difficulty_counts()
    topic_counts = load_topic_counts()
    block = build_stats_block(easy, medium, hard, solved, topic_counts)
    update_readme(block)


if __name__ == "__main__":
    main()
