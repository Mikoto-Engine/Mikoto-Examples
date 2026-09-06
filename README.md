# Mikoto Examples

A collection of examples, sandbox projects, experiments, and tests built with the [Mikoto Engine](https://github.com/kateBea/Mikoto.git).

Mikoto Examples is the companion repository for the Mikoto Engine. It contains projects that use the engine as an external dependency, providing a separate space for experimentation, demonstrations, and testing without adding application-specific code to the core engine repository.

---

## Overview

The repository is intended to showcase and exercise the capabilities of Mikoto through small examples, experimental applications, and test projects.

The Mikoto Engine is maintained separately and included here as a Git submodule. This keeps the engine focused on its core systems while allowing applications and experiments to evolve independently.

## Getting Started

Clone the repository together with its submodules:

```bash
git clone --recursive https://github.com/Mikoto-Engine/Mikoto-Examples.git
cd Mikoto-Examples
```

If the repository was cloned without initializing its submodules, run:

```bash
git submodule update --init --recursive
```

For platform requirements, dependencies, CMake configuration, and build instructions, see the **[Building Guide](BUILDING.md)**.

---

## Building

Mikoto Examples uses **CMake** for project configuration and building.

The repository is currently developed and tested on **Windows** and **Linux**. The included projects can be built according to the selected CMake configuration.

For complete setup instructions, including platform-specific requirements and dependencies, see the **[Building Guide](BUILDING.md)**.

## License

This repository is distributed under the terms described in [LICENSE](LICENSE).

The Mikoto Engine and its third-party dependencies are subject to their respective licenses. See the relevant repositories and included license files for additional information.