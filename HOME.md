---
tags:
  - dashboard
---
# Dashboard

## Today's Learning

```dataviewjs
const today = dv.date("today");
const todayStr = today.toISODate();

const todayFiles = dv.pages('"01 solutions"')
  .where(p => p.file.name !== "README")
  .where(p => {
    const created = dv.date(p.created);
    return created && created.toISODate() === todayStr;
  })
  .sort(p => p.file.mtime, "desc");

if (todayFiles.length === 0) {
  dv.paragraph("No files created today.");
} else {
  dv.table(
    ["File", "Difficulty", "Status", "Type"],
    todayFiles.map(p => {
      const tags = Array.isArray(p.tags) ? p.tags : (p.tags ? [p.tags] : []);
      const type = tags.includes("algorithm") ? "Algorithm" : "Problem";
      return [
        p.file.link,
        p.difficulty || "",
        p.status || "",
        type
      ];
    })
  );
}
```

## Reviews Due Today

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
  .where(p => p.lastReviewed && p.reviewCount !== undefined && p.reviewCount < 6);

const due = all.map(p => {
  const lastReview = dv.date(p.lastReviewed);
  const count = p.reviewCount || 0;
  const intervals = getIntervals(p.difficulty);
  const interval = intervals[Math.min(count, intervals.length - 1)];
  const nextDue = lastReview.plus({days: interval});
  const topic = extractTopic(p.tags);
  return {p, lastReview, count, interval, nextDue, topic};
}).filter(d => d.nextDue <= today);

if (due.length === 0) {
  dv.paragraph("No reviews due today. Keep learning!");
} else {
  dv.table(
    ["File", "Last Review", "Review Count", "Interval (days)", "Difficulty", "Topic"],
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

## Solved Problems

```dataviewjs
const all = dv.pages('"01 solutions"')
  .where(p => p.file.name !== "README")
  .where(p => {
    const tags = Array.isArray(p.tags) ? p.tags : (p.tags ? [p.tags] : []);
    return tags.includes("dsa/problem");
  })
  .where(p => p.status === "solved" || p.status === "review")
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

if (all.length === 0) {
  dv.paragraph("No solved problems yet.");
} else {
  dv.table(
    ["File", "Difficulty", "Status", "Reviews", "Last Review", "Topic"],
    all.map(p => [
      p.file.link,
      p.difficulty || "",
      p.status || "",
      p.reviewCount || 0,
      p.lastReviewed || "",
      extractTopic(p.tags)
    ])
  );
}
```

## Algorithms

```dataviewjs
const all = dv.pages('"01 solutions"')
  .where(p => p.file.name !== "README")
  .where(p => {
    const tags = Array.isArray(p.tags) ? p.tags : (p.tags ? [p.tags] : []);
    return tags.includes("algorithm");
  })
  .where(p => p.status === "solved" || p.status === "review")
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

if (all.length === 0) {
  dv.paragraph("No algorithms yet.");
} else {
  dv.table(
    ["File", "Difficulty", "Status", "Reviews", "Last Review", "Topic"],
    all.map(p => [
      p.file.link,
      p.difficulty || "",
      p.status || "",
      p.reviewCount || 0,
      p.lastReviewed || "",
      extractTopic(p.tags)
    ])
  );
}
```

## Statistics

```dataviewjs
const all = dv.pages('"01 solutions"').where(p => p.file.name !== "README");

const total = all.length;
const solved = all.where(p => p.status === "solved" || p.status === "review").length;
const problems = all.where(p => {
  const tags = Array.isArray(p.tags) ? p.tags : (p.tags ? [p.tags] : []);
  return tags.includes("dsa/problem") && (p.status === "solved" || p.status === "review");
}).length;
const algorithms = all.where(p => {
  const tags = Array.isArray(p.tags) ? p.tags : (p.tags ? [p.tags] : []);
  return tags.includes("algorithm") && (p.status === "solved" || p.status === "review");
}).length;
const easyCount = all.where(p => p.difficulty === "Easy" || p.difficulty === "easy").length;
const mediumCount = all.where(p => p.difficulty === "Medium" || p.difficulty === "medium").length;
const hardCount = all.where(p => p.difficulty === "Hard" || p.difficulty === "hard").length;

dv.table(
  ["Metric", "Count"],
  [
    ["Total", total],
    ["Solved", solved],
    ["Solved Problems", problems],
    ["Solved Algorithms", algorithms],
    ["Easy", easyCount],
    ["Medium", mediumCount],
    ["Hard", hardCount]
  ]
);
```
