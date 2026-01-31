Project: Quest12 (single-file C++ exercises)

Overview
- This repository contains a single C++ source: `Quest.cc` (author header: Wayne Mack). The project is a single-file exercise rather than a multi-module app.

What to expect
- No build system, tests, or CI configured — treat changes as small, self-contained edits to `Quest.cc`.
- Keep changes minimal and localized: prefer editing `Quest.cc` in-place rather than adding large scaffolding.

Build / Run
- Linux / macOS / MinGW: `g++ -std=c++17 Quest.cc -O2 -o Quest && ./Quest`
- clang: `clang++ -std=c++17 Quest.cc -O2 -o Quest && ./Quest`
- Windows (MSVC): `cl /EHsc Quest.cc && Quest.exe`

Project-specific patterns
- Single-file solutions: place helper functions above `main()` or in an anonymous namespace in `Quest.cc`.
- Top-of-file header comments are used for author/project info — preserve or update them when modifying the file.
- Avoid introducing external dependencies or new build tooling unless requested.

Editing guidance for AI agents
- Make the smallest correct change. If you add includes, add only those required (e.g., `<iostream>`, `<vector>`).
- Preserve the existing file header and overall single-file layout.
- When adding I/O examples, prefer stdin/stdout usage compatible with online judges.

Files to inspect
- [Quest.cc](Quest.cc#L1)

When to escalate to the human
- You need to add a multi-file build system, unit tests, or external libraries.
- You plan to refactor into modules or change repository layout.

If anything in this file seems incomplete or you want broader repo changes, ask the maintainer before proceeding.

Please review and tell me which sections need more detail or examples.
