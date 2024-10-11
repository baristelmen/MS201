<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/baristelmen/MS201">
    <img src="images/logo.png" alt="Logo" width="80" height="80" />
  </a>

  <h3 align="center">MS201 - Travaux pratiques (TP) #5</h3>

  <p align="center">
    Modeling behavior of materials using python
    <br />
    <a href="https://github.com/baristelmen/MS201/archive/refs/heads/main.zip">Download</a>
    ·
    <a href="https://github.com/baristelmen/MS201/issues">Report Bug</a>
    ·
    <a href="https://github.com/baristelmen/MS201/pulls">Request Feature</a>
  </p>
</div>

## Table of Contents

* [About this repository](#about-this-repository)
  * [Overview](#overview)
  * [Features](#features)
  * [Why containers?](#why-containers)
* [Getting started](#getting-started)
  * [Setting up the environment](#setting-up-the-environment)
  * [Using this repo](#using-this-repo)
* [Getting Help](#getting-help)
  * [Issues tab](#1-issues-tab)
  * [Software related issues](#2-software-related-issues)
  * [Contact maintainer](#3-contact-maintainer)
* [Contributing](#contributing)
* [License](#license)


## About this repository

### Overview

This repository provides a Docker Compose setup for running a JupyterLab environment with pre-installed TFEL/MFront. This setup allows you to perform material behavior simulations using the Python bindings of TFEL/MFront in JupyterLab. Essentialy, the compose file will be fetching image specially created for **MEC_4MS01_TA** course which is named,  ``` jupyter-mfront-ms201 ```. 

### Features

- **Jupyter Lab**: Jupyter Lab is a powerful web-based interactive development environment for Python and other programming languages. It comes pre-configured with essential libraries and tools for data analysis, machine learning, and more.

- **MFront**: MFront is an open-source modeling and simulation tool commonly used in mechanical engineering and materials science. This project includes a configured MFront environment for your modeling needs.

- **Docker Compose**: Docker Compose simplifies the management of multi-container applications. With just a few commands, you can spin up your Jupyter Lab and MFront containers and start working on your projects.

### How to Use

To get started with this project, follow the installation and usage instructions in the [Installation Guide](#installation-guide) and [Usage Guide](#usage-guide) sections of this README.

## Getting Started

### Setting up the environment

This repo uses Docker to run its services contrary to classical VMs. Ensure your system meets the specified requirements before proceeding.

#### System Requirements

**Linux:**
- A compatible CPU with hardware virtualization support (for running Docker containers).
- At least 2GB of RAM.
- A network connection

**Windows:**
- Windows 10 64-bit: Home, Pro, or Enterprise edition.
- Virtualization must be enabled in BIOS/UEFI settings.
- Hyper-V must be disabled if enabled.
- Docker Desktop for Windows requires Microsoft Hyper-V.
- A network connection.

**macOS:**
- A 2010 or newer Mac with macOS 10.13 or later.
- macOS Sierra or later.
- At least 4GB of RAM.
- A network connection.

Docker supports multiple Linux distros at its current stage and provides .deb and .rpm packages. To proceed with installation process, follow the link below for official instructions.

https://docs.docker.com/engine/install/

This repo uses docker-compose plugin. Normally, it should be installed via standard docker installation. If not, refer to Docker documentation for proper installation instructions.

## Using this repo

To use this repo, one can either download or clone. We do not provide versions or tags on this repo.

To clone this repository,

```console
git clone https://github.com/baristelmen/MS201.git
```

To download this repository
```console
https://github.com/baristelmen/MS201/archive/refs/heads/main.zip
```
Once you have the source code, follow the steps below (Identical for each OS):

1. Unzip the folder on your computer 
2. Open you favorite terminal on your preferred OS and navigate to the unzipped folder
3. An environment file (.env) is provided in this repository. This file can be either modified or leave as it is.
4. At the source code folder, execute the following command
   ```shell
   docker compose up -d
5. This command will download the appropriate image, based on your CPU architechture, on your local machine. The download could take some time. So make sure that you have enough coffee.
6. The jupyter lab is already installed on your computer and mildly configured. To access to your jupyter lab interface, open your favorite browser and type the address as below (or the ip address)
   ```shell
   http://localhost:8888/lab
7. The default password configured in **.env** file is **MS201**. 
8. The data stored in the docker images can be accessed from your computer via data folder given in this repository. Interactive sharing folder definition is pre-configured in **docker-compose.yaml** file. You can always access to your data from this folder including your simulations results or your custom python codes. 

## Getting Help

If you encounter any issues or have questions while using this environment, here are a few ways you can seek assistance:

### 1. **Issues Tab**

For bugs, feature requests, or general questions, please open an issue in the [Issues tab](#). Be sure to provide as much detail as possible, including:
- Steps to reproduce the issue.
- Any error messages or logs.
- Your environment details (e.g., Docker version, system configuration).

### 2. **Software related issues**

For help with TFEL/MFront, you can consult the official documentation:
- [TFEL Documentation](https://thelfer.github.io/tfel/web/index.html)
- [MFront User Guide](https://thelfer.github.io/tfel/web/mfront-userguide.html)

For Docker-related issues, you can refer to:
- [Docker Documentation](https://docs.docker.com)
- [Docker Compose Documentation](https://docs.docker.com/compose)
 
### 3. **Contact Maintainer**

If your issue is specific to this repository, feel free to contact the maintainer directly by creating an issue or posting a comment. 

## Contributing
Contributions to this repository are welcome! If you encounter issues or have improvements to suggest, please feel free to open an issue or submit a pull request.

## License
This repository is open-source and distributed under the MIT License. You are free to use, modify, and distribute it according to the terms of the license.
