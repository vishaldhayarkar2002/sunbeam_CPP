# 📋 C++ OOP Notes Generation — Instructions for Antigravity

> **Usage**: Tell Antigravity: *"Read the file `notesInstructions.md` in my CPP folder and generate notes for Day N"*
> Or simply: *"Follow `notesInstructions.md` for Day4"*

---

## Goal

Generate a **comprehensive, deeply explained, properly formatted Markdown study-notes artifact** for a given Day/Module of the C++ OOP course. The notes must reference **every code example** from that day's `codes/` folder and integrate the **theory from the day's PDF** into a single, self-contained document.

---

## Folder Structure (Same for Every Day)

```
CPP/
├── Day1/
│   ├── Day1.pdf              ← Theory overview (slides)
│   ├── codes/                ← Code examples organized by topic
│   │   ├── topic_folder_1/
│   │   │   ├── DayN_1.cpp
│   │   │   ├── DayN_2.cpp
│   │   │   └── ...
│   │   ├── topic_folder_2/
│   │   │   └── ...
│   │   └── standalone.cpp    ← Some files may be directly in codes/
│   ├── Assignment/           ← (optional) Ignore for notes
│   └── images/               ← (optional) Ignore for notes
├── Day2/
│   ├── Day2.pdf
│   ├── codes/
│   │   └── ...
├── DayN/
│   ├── DayN.pdf              ← May also have DayN_Help.pdf
│   ├── codes/
│   │   └── ...
├── notesInstructions.md      ← THIS FILE
└── ...
```

### Key Conventions

- The **PDF** in the Day folder (e.g., `Day4.pdf`) contains the **theory slides**. There may also be a helper PDF (e.g., `Day04_Help.pdf`).
- The **`codes/`** subfolder contains **topic-organized subfolders** (e.g., `constructor/`, `namespace/`, `this_pointer/`). Each subfolder contains numbered `.cpp` files demonstrating that topic.
- Sometimes `.cpp` files sit directly in `codes/` without a subfolder.
- Sometimes extra `.cpp` files (assignments, practice) sit directly in the `DayN/` folder itself — include these too if they demonstrate taught concepts.
- **Ignore**: `.exe` files, `output/` folders, `images/` folders, `Assignment/` folders, `.git`, `.vscode`.

---

## Step-by-Step Process

### Step 1: Discover Structure

1. List the contents of `CPP/DayN/` to find the PDF(s) and any standalone `.cpp` files.
2. List `CPP/DayN/codes/` to discover all topic subfolders and standalone code files.
3. Recursively list each subfolder inside `codes/` to find all `.cpp` files.

### Step 2: Extract Theory from PDF(s)

1. Use Python with `PyPDF2` to extract text from `DayN.pdf` (and `DayN_Help.pdf` if present).
2. Use `sys.stdout.reconfigure(encoding='utf-8')` to handle special characters.
3. Extract page-by-page. Each page usually maps to a slide/topic.
4. The PDF text gives you: **topic names, definitions, bullet points, rules, and key concepts**.

```python
import PyPDF2, sys
sys.stdout.reconfigure(encoding='utf-8')
reader = PyPDF2.PdfReader(r'path\to\DayN.pdf')
for i, page in enumerate(reader.pages):
    try:
        text = page.extract_text()
        if text:
            print(f'PAGE {i+1}: {text[:600]}')
    except: pass
```

### Step 3: Read All Code Files

1. Read **every single `.cpp` file** in the `codes/` directory and its subfolders.
2. Read any standalone `.cpp` files in the `DayN/` folder itself.
3. Understand what each file demonstrates by reading its comments and code structure.
4. Note the **topic subfolder name** — it tells you what concept the code belongs to (e.g., `constructor/`, `inline_function/`, `const/`).

### Step 4: Generate the Notes Artifact

Create a single Markdown artifact file named `cpp_notes_moduleN.md` in the artifact directory.

---

## Output Format & Structure

### File Naming

```
cpp_notes_moduleN.md
```

Where `N` matches the Day number.

### Document Structure

```markdown
# 📘 Module N — [Descriptive Title Covering Main Topics]

> **Course**: Object Oriented Programming Using C++
> **Instructor**: Ketan G Kore
> **Source Files**: [DayN codes](file:///path/to/DayN/codes) | [DayN.pdf](file:///path/to/DayN.pdf)

---

## Table of Contents

1. [Topic 1 Title](#1-topic-1-title)
2. [Topic 2 Title](#2-topic-2-title)
...

---

## 1. Topic 1 Title

### Subtopic explanation...

[Content here]

---

## 2. Topic 2 Title

[Content here]

---

> **Previous Module**: [← Module N-1 — ...](file:///path/to/previous)
> **Next Module**: [Module N+1 — ... →](file:///path/to/next)  (if applicable)
```

---

## Content Rules (CRITICAL — Follow Exactly)

### 1. Topic Organization

- Group content by **topic subfolder** (e.g., all files in `constructor/` go under a "Constructors" section).
- Order topics logically following the **PDF slide order** — the PDF reveals the teaching sequence.
- Within a topic, present code files in **numerical order** (Day3_4.cpp before Day3_5.cpp).
- Each topic gets its own `## Section` heading.

### 2. Theory Integration

- Start each section with **theory from the PDF**: definitions, bullet points, rules.
- Rephrase and expand the PDF bullet points into **full, clear explanations** — don't just copy terse slide text.
- Use tables for comparisons, rules summaries, and property listings.

### 3. Code Examples (MOST IMPORTANT)

For every `.cpp` file:

- **Include the code** as a fenced C++ code block — cleaned up (remove `\r`, fix formatting).
- **Link to the source file** using `[DayN_X.cpp](file:///absolute/path)` format.
- **Explain what the code demonstrates** — don't just paste code. Explain:
  - What concept it illustrates
  - How it works line-by-line (for non-trivial code)
  - What the expected output is
  - What would happen if you uncommented commented-out lines
  - Common mistakes the example warns against
- If a file contains multiple `main` functions (e.g., `main1()`, `main2()`, `main3()`, `main()`), explain **each variant separately** — they show progressive learning steps.
- Use **inline comments** in code blocks to highlight key points.
- If code shows a "wrong" approach (e.g., call-by-value not working), explain **why** it fails.

### 4. Formatting Elements to Use

| Element | When to Use |
|---|---|
| `> [!NOTE]` | Background context, implementation details, helpful explanations |
| `> [!TIP]` | Best practices, performance tips, pro advice |
| `> [!IMPORTANT]` | Essential requirements, critical steps, must-know information |
| `> [!WARNING]` | Potential problems, breaking changes, subtle bugs |
| `> [!CAUTION]` | High-risk actions, undefined behavior, data loss risks |
| **Tables** | Comparisons, rule summaries, property listings, type mappings |
| **Code blocks** | Every `.cpp` file, pseudocode, syntax examples |
| **Inline code** | Keywords, function names, variable names, types |
| **Bold** | Key terms on first introduction |
| **Clickable file links** | Every referenced `.cpp` file |

### 5. Depth & Completeness Requirements

- **Every `.cpp` file** must be referenced and explained — no file should be skipped.
- Show the **progression** between related examples (e.g., Day3_4 → Day3_5 → Day3_6 shows evolution from manual init → constructor).
- Explain **WHY** something works that way, not just WHAT it does.
- Include **memory diagrams** (ASCII art) for pointer/memory topics.
- Include **execution flow** explanations for complex examples (e.g., constructor delegation order).
- Add **summary tables** at the end of major sections.
- Point out **common pitfalls** explicitly with WARNING/CAUTION callouts.

### 6. Navigation

- Add a link to the **previous module** at the bottom (if it exists).
- Add a link to the **next module** at the bottom (as a placeholder — it may not exist yet).
- Use the format: `file:///C:/Users/daksh/.gemini/antigravity-ide/brain/<conversation-id>/cpp_notes_moduleN.md`

### 7. Artifact Metadata

When creating the artifact, set:
- `UserFacing`: `true`
- `RequestFeedback`: `false`
- `Summary`: A detailed multi-line summary listing all topics covered with brief descriptions.

---

## Example Section (For Reference)

Here's what a well-written section looks like:

```markdown
## 6. Parameterless Constructor (Zero-Argument / Default)

### Solution: Use a Constructor — [Day3_6.cpp](file:///path/to/Day3_6.cpp)

⟨code block with full cleaned code⟩

### When the Constructor is NOT Called

⟨code block showing pointer/reference cases⟩

### Access Specifier on Constructors — [Day3_7.cpp](file:///path/to/Day3_7.cpp)

⟨code block⟩

⟨table: Constructor Access vs Where Object Can Be Created⟩
```

Notice:
- Section starts with theory
- Each code file gets a subsection with a clickable link
- Code is followed by explanation
- Tables summarize rules
- Callouts highlight gotchas

---

## Checklist Before Finishing

- [ ] Every `.cpp` file in `codes/` and its subfolders is referenced
- [ ] Every `.cpp` file in the `DayN/` root (if relevant) is referenced
- [ ] All theory from the PDF is incorporated
- [ ] Code blocks are clean (no line numbers, no encoding artifacts)
- [ ] File links use absolute paths with `file:///` scheme
- [ ] Tables are used for all comparisons and rule summaries
- [ ] At least one callout (NOTE/TIP/WARNING/etc.) per major section
- [ ] Table of Contents matches all `##` headings
- [ ] Navigation links at bottom point to prev/next modules
- [ ] No topic is just code without explanation
- [ ] No explanation is just theory without code
