# GEMINI.md - MechFlow Project Context

This document provides essential context and instructions for the Gemini CLI agent working on the MechFlow project. Please read this file at the beginning of each session to quickly re-establish context.

## 1. Project Overview

**Project Name:** MechFlow
**Goal:** To develop a CAD application with a focus on C++ modern practices, multi-platform compatibility (starting with Manjaro Linux), and future AI-driven development.

## 2. Current Project State

**Week:** Week 1
**Day:** Day 2 (CAD Kernel Selection & Integration Strategy) is **COMPLETE**.

*   **Build System:** CMake is configured.
*   **Version Control:** Git repository initialized and synchronized with `https://github.com/Novav20/mech-flow-cad.git`.
*   **Development Environment:** A Docker-based environment is set up and functional.
*   **Dependency Manager:** vcpkg has been selected and is available within the Docker environment.
*   **Initial Code:** A minimal `src/main.cpp` exists, compiles, and runs successfully.

## 3. Development Environment (Docker)

MechFlow uses Docker to ensure a consistent and reproducible development environment.

*   **Docker Image:** `mcr.microsoft.com/devcontainers/cpp:1-bookworm`
*   **`docker-compose.yml`:** Configures the Docker service, mounts the project directory (`.`) to `/app` inside the container, and sets the user to match your host UID/GID for proper file permissions.
*   **`.env` file:** Contains your `UID` and `GID` (e.g., `UID=1000`, `GID=1000`) to ensure correct file ownership within the mounted volume.

**Key Commands for Docker:**
*   **Start/Rebuild Container:** `docker-compose up -d --build`
*   **Stop Container:** `docker-compose down`
*   **Access Container Shell:** `docker-compose exec dev bash` (This is where you'll run most build/test commands)

## 4. Build System (CMake)

CMake is used for managing the build process.

*   **Build Directory:** All build artifacts are generated in the `build/` directory.

**Key Commands for Building (run *inside* the Docker container shell, or using `docker-compose exec`):**
*   **Configure CMake:** `cmake ..` (run from `/app/build`)
*   **Compile Project:** `make` (run from `/app/build`)
*   **Clean Build:** `make clean` (run from `/app/build`)

## 5. Dependency Management (vcpkg)

vcpkg is the chosen dependency manager. It is pre-installed and configured within the `mcr.microsoft.com/devcontainers/cpp:1-bookworm` Docker image.

## 6. Git Workflow

*   **Commit Messages:** Follow conventional commits (e.g., `feat:`, `fix:`, `docs:`).
*   **Pushing Changes:** `git push` (after `git add` and `git commit`).
*   **Commit Condition:** Only commit and push changes when the application successfully compiles and executes. This ensures a stable and working state after each commit.

## 7. Project Structure

```
MechFlow/
├── .git/
├── .gitignore
├── CMakeLists.txt
├── docker-compose.yml
├── .env
├── DEVIATIONS.md
├── GEMINI.md
├── src/
│   ├── Geometry/
│   │   └── CMakeLists.txt
│   ├── UI/
│   │   └── CMakeLists.txt
│   ├── Rendering/
│   │   └── CMakeLists.txt
│   ├── Core/
│   │   └── CMakeLists.txt
│   └── main.cpp
├── tests/
│   └── CMakeLists.txt
└── build/ (generated by CMake)
```

## 8. Important Notes for Gemini

*   **Context is Key:** Always refer to this `GEMINI.md` file and the `DEVIATIONS.md` file for project context and history.
*   **Adhere to Plan:** Follow the weekly milestones and daily breakdowns provided by the user. If a deviation is necessary, document it in `DEVIATIONS.md`.
*   **Verify:** Before declaring a task complete or moving to the next step, ensure the project compiles and runs successfully (if applicable).
*   **User Confirmation:** For significant changes or if unsure, always confirm with the user.
*   **No Assumptions:** Do not assume libraries, frameworks, or tools are available unless explicitly stated in the plan or confirmed by existing project files (e.g., `CMakeLists.txt`, `vcpkg.json`).
*   **Documentation Updates:** After each commit, update `GEMINI.md` and `DEVIATIONS.md` (if necessary) to reflect the latest project state and any deviations.

**Next Steps:** The project is ready to proceed with Day 2 tasks as per the weekly plan.