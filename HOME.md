---
tags:
  - dashboard
---
# HOME

## Bài cần review hôm nay


```dataviewjs
const schedules = {
  Easy: [3, 7, 15, 30, 60, 120, 240],
  Medium: [1, 3, 7, 14, 30, 60, 120],
  Hard: [1, 2, 4, 7, 14, 30, 60]
};

function getIntervals(difficulty) {
  const d = String(difficulty || "Medium").toLowerCase();

  if (d === "easy") return schedules.Easy;
  if (d === "hard") return schedules.Hard;
  return schedules.Medium;
}

function extractTopic(tags) {
  const tagList = Array.isArray(tags) ? tags : (tags ? [tags] : []);
  const topicTags = tagList
    .map(t => String(t))
    .filter(t => t.toLowerCase().startsWith("dsa/topic"));

  if (topicTags.length === 0) return "";
  return topicTags
    .map(tag => {
      const parts = tag.split("/");
      return parts.slice(2).join("/");
    })
    .join(", ");
}

const today = dv.date("today");

const all = dv.pages('"01 solutions"')
  .where(p => p.status === "solved" || p.status === "review")
  .where(p => p.lastReviewed);

const due = all.map(p => {
  const lastReview = dv.date(p.lastReviewed);
  const count = p.reviewCount || 0;
  const intervals = getIntervals(p.difficulty);
  const interval = intervals[Math.min(count, intervals.length - 1)];
  const nextDue = lastReview.plus({days: interval});
  const topic = extractTopic(p.tags);
  return {p, lastReview, count, interval, nextDue, topic};
}).filter(d => today >= d.nextDue);

if (due.length === 0) {
  dv.paragraph("Không có bài nào cần review hôm nay. Tiếp tục học theo roadmap!");
} else {
  dv.table(
    ["Bài", "Last review", "Lần đã review", "Interval (ngày)", "Difficulty", "Topic"],
    due.map(d => [
      d.p.file.link,
      d.p.lastReviewed,
      d.count,
      d.interval,
      d.p.difficulty || "",
      d.topic
    ])
  );
}
```

## Tổng hợp tất cả solutions

Filter bằng cách click header cột.

```dataviewjs
const all = dv.pages('"01 solutions"')
  .where(p => p.file.name !== "README")
  .sort(p => p.file.mtime, "desc");

function extractTopic(tags) {
  const tagList = Array.isArray(tags) ? tags : (tags ? [tags] : []);
  const topicTags = tagList
    .map(t => String(t))
    .filter(t => t.toLowerCase().startsWith("dsa/topic"));

  if (topicTags.length === 0) return "";
  return topicTags
    .map(tag => {
      const parts = tag.split("/");
      return parts.slice(2).join("/");
    })
    .join(", ");
}

dv.table(
  ["Bài", "Difficulty", "Status", "Reviews", "Last review", "Topic"],
  all.map(p => [
    p.file.link,
    p.difficulty || "",
    p.status || "",
    p.reviewCount || 0,
    p.lastReviewed || "",
    extractTopic(p.tags)
  ])
);
```

## Thống kê

```dataviewjs
const all = dv.pages('"01 solutions"').where(p => p.file.name !== "README");

const total = all.length;
const solved = all.where(p => p.status === "solved" || p.status === "review").length;
const easyCount = all.where(p => p.difficulty === "Easy" || p.difficulty === "easy").length;
const mediumCount = all.where(p => p.difficulty === "Medium" || p.difficulty === "medium").length;
const hardCount = all.where(p => p.difficulty === "Hard" || p.difficulty === "hard").length;

dv.table(
  ["Metric", "Count"],
  [
    ["Tổng số bài", total],
    ["Đã solved", solved],
    ["Easy", easyCount],
    ["Medium", mediumCount],
    ["Hard", hardCount]
  ]
);
```
