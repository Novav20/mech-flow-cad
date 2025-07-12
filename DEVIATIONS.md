# MechFlow - Week 1: Deviations Report

This document outlines the deviations from the original Week 1 plan for MechFlow, specifically focusing on Day 1 activities.

## Day 1 Deviations (Project Setup & Build System)

### 1. Dependency Manager Selection
- **Planned:** Conan
- **Actual:** vcpkg
- **Reason:** User request to switch from Conan to vcpkg for dependency management.

### 2. Docker Environment Setup (Unplanned but Necessary)
- **Planned:** Not explicitly detailed in the daily breakdown, assumed a straightforward setup.
- **Actual:** Significant time and effort were spent on configuring a robust and portable Docker-based development environment. This involved:
    - Initial attempts with a custom `Dockerfile` based on Ubuntu, installing `cmake`, `git`, and `vcpkg`.
    - Encountered persistent `apt-get` date validation errors due to the system's future date setting (July 12, 2025, vs. current repository validity).
    - Attempted various workarounds including `Acquire::Check-Valid-Until=false` and switching to `old-releases.ubuntu.com` (which proved incompatible with the Ubuntu version).
    - Switched to a Debian base image, which also exhibited similar date validation issues.
    - **Resolution:** Adopted `mcr.microsoft.com/devcontainers/cpp:1-bookworm` as the base Docker image. This pre-configured image includes `vcpkg` and all necessary development tools, effectively bypassing the `apt-get` date validation problems.

### 3. File Permissions Issues (Unplanned but Necessary)
- **Planned:** Not anticipated.
- **Actual:** Encountered file permission issues within the Docker volume. Directories created by the `root` user inside the container were inaccessible to the host user.
- **Resolution:**
    - Modified `docker-compose.yml` to include the `user: "${UID}:${GID}"` directive, ensuring the container runs with the host user's permissions.
    - Created a `.env` file to provide the `UID` and `GID` environment variables to `docker-compose`.
    - Required a manual `sudo chown -R $(id -u):$(id -g) .` command to be executed by the user on the host machine to correct permissions for already existing files/directories.

### 4. Initial Code Generation for Verification
- **Planned:** Boilerplate code generation was scheduled for Day 6 (Saturday).
- **Actual:** A minimal `src/main.cpp` was created on Day 1 to serve as a basic executable. This was crucial for verifying the successful setup of the CMake build system and the Docker environment (compilation and execution within the container).

---

**Summary:** While the core objectives of Day 1 (project initialization, build system setup, and Git integration) were met, the process involved significant unplanned effort in establishing a functional Docker environment and resolving associated permission issues. The choice of dependency manager was also changed based on user preference. These deviations were necessary to ensure a stable and reproducible development environment for future work.