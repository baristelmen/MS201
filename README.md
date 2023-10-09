<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/baristelmen/MS201">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">MS201 - Travaux pratiques (TP) #5</h3>

  <p align="center">
    Behavior law identification using MFront in a docker container
    <br />
    <a href="#">Download</a>
    ·
    <a href="#">View Demo</a>
    ·
    <a href="#">Report Bug</a>
    ·
    <a href="#">Request Feature</a>
  </p>
</div>

## Table of Contents

* [Introduction](#introduction)
* [Getting help](#getting-help)
* [About this repository](#about-this-repository)
  * [Overview](#overview)
  * [Features](#features)
  * [Why containers?](#why-containers)
* [Getting started](#getting-started)
  * [Setting up the environment](#setting-up-the-environment)
  * [Using this repo](#using-this-repo)
* [Contributing](#contributing)
* [License](#license)


## Introduction

Material response under static and dynamic loading and behavior law modeling are fundamental concepts in materials science and engineering. Understanding how materials behave under different loading conditions is crucial for designing and analyzing structures and components. Let's explore these topics in detail:

### Material Response Under Static and Dynamic Loading:

When a material is subjected to static loading, it means that the applied force or load is applied slowly and does not change over time. In this scenario, the material deforms and reaches a stable equilibrium without any significant fluctuations. The key aspects of material response under static loading include:

<ol>
<li> Elastic Behavior: When a material is loaded within its elastic limit, it deforms reversibly. This means that it returns to its original shape once the load is removed. Hooke's Law describes this behavior, stating that stress (force per unit area) is directly proportional to strain (deformation).

<li> Plastic Behavior: If the applied stress exceeds the material's yield strength, it undergoes plastic deformation. Plastic deformation is permanent and non-reversible, meaning the material does not return to its original shape after unloading.

<li> Failure: If the applied stress exceeds the ultimate strength of the material, it may result in failure, such as fracture or rupture.
</ol>

Dynamic loading involves rapidly changing or fluctuating forces or loads over time. Unlike static loading, dynamic loading can lead to time-dependent responses in materials. Key aspects of material response under dynamic loading include:

<ol>
<li> Inertia Effects: Under dynamic loading, the mass of the material becomes significant, leading to inertia effects. These effects can cause oscillations and vibrations in the material, which are not observed in static loading.
<li> Strain Rate Sensitivity: Many materials exhibit strain rate sensitivity, meaning their mechanical properties (e.g., stiffness, strength) change with the rate of deformation. This is particularly important in dynamic loading scenarios.
<li> Fatigue: Repeated dynamic loading, even if below the material's ultimate strength, can lead to fatigue failure over time due to the accumulation of damage and microcracks.
</ol>

**Behavior Law Modeling:**

Behavior law modeling involves the mathematical representation of material behavior under various loading conditions. This modeling is essential for predicting how materials will respond to different loads and designing structures accordingly. Common behavior law models include:

<ol>
<li> Linear Elastic Model: This model assumes that the material behaves elastically up to a certain stress (elastic limit), following Hooke's Law. Beyond this limit, it is assumed to be perfectly plastic. This model is relatively simple but may not accurately represent the behavior of all materials.
<li> Nonlinear Elastic Models: These models consider nonlinear stress-strain relationships within the elastic range and are more accurate for certain materials like rubber.
<li> Plasticity Models: Plasticity models, such as the Von Mises yield criterion, describe the material's plastic behavior. They account for strain hardening (increase in yield strength with plastic deformation) and are widely used in engineering simulations.Getting Started
<li> Viscoelastic Models: These models consider both elastic and viscous behavior, suitable for materials that exhibit time-dependent responses, like polymers.
<li> Damage Models: For predicting failure in materials, damage models are used. They consider factors like crack propagation and material degradation over time, critical in fatigue analysis.
<li> Finite Element Analysis (FEA): FEA combines behavior law modeling with numerical methods to analyze complex structures under various loading conditions. It divides structures into finite elements and calculates their response to loads.
</ol>

Behavior modeling is a critical aspect of materials science and engineering, as it involves understanding and predicting how materials respond to various mechanical, thermal, and environmental conditions. Accurate behavior modeling is essential for designing and analyzing structures, components, and systems across a wide range of industries, from aerospace and automotive to civil engineering and biomechanics.

One tool that plays a significant role in behavior modeling is MFront. MFront is an open-source software framework designed for the definition of complex material behaviors, particularly in the context of finite element simulations and other numerical analyses. Let's delve into behavior modeling and explore how MFront fits into this field.

Key aspects of behavior modeling include:

<ol>
<li> Constitutive Models: Constitutive models describe the relationship between stress (internal forces) and strain (deformation) in a material. These models can be linear or nonlinear, isotropic or anisotropic, and time-dependent or time-independent, depending on the material's behavior.

<li> Material Parameters: Behavior models often require material-specific parameters, such as elastic moduli, yield strengths, thermal conductivities, and coefficients of thermal expansion. These parameters are determined through experimentation or estimation.

<li> Boundary and Initial Conditions: Models must account for boundary conditions (how a material interacts with its surroundings) and initial conditions (the material's state at the beginning of a simulation). These conditions can significantly influence the material's response.

<li> Validation: Validating behavior models involves comparing model predictions to experimental data to ensure accuracy and reliability. Iterative refinement may be necessary to improve model accuracy.
</ol>

### MFront

[MFront](https://github.com/thelfer/tfel) is a powerful and versatile tool for creating and implementing constitutive models for materials. It is particularly well-suited for finite element simulations and other numerical analyses. Here's an overview of MFront's key features and capabilities:

<ol>
<li> Modular Framework: MFront provides a modular framework for defining complex material behaviors. Engineers and researchers can write user-defined material models using a simple, domain-specific language.

<li> Extensibility: Users can implement a wide range of material models, including linear elasticity, plasticity, viscoelasticity, damage mechanics, and more. MFront's extensibility allows it to accommodate a variety of material behaviors.

<li> Code Generation: MFront generates C++ code from the user-defined material models. This code can then be integrated into finite element analysis (FEA) software packages, such as Code_Aster, Cast3M, or Abaqus.

<li> Integration with FEA: MFront's seamless integration with FEA software enables engineers to simulate complex structures and systems with accurate material behavior representation.

<li> Material Database: MFront can store material models in a library for easy reuse and sharing among researchers and engineers.

<li> Cross-Platform Support: MFront is compatible with various operating systems, making it accessible to a broad user base.
</ol>

In summary, behavior modeling is a fundamental aspect of materials science and engineering, enabling the prediction of material responses under different conditions. MFront, as an open-source framework, empowers researchers and engineers to create and implement complex material models efficiently, making it a valuable tool for advancing our understanding of materials and optimizing designs in various industries.

## About this repository

### Overview
This repository is a Docker Compose-based project that allows you to set up Jupyter Lab and MFront environments quickly and efficiently. Whether you're working on data science projects with Jupyter Lab or utilizing MFront for modeling and simulation tasks, this project simplifies the setup process.

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
- A network connection to download Docker packages.

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

To utilize the environment defined in this repository, first, the repository has to be either cloned or downloaded to your local machine. 

To clone this repository,

```console
git clone https://github.com/baristelmen/repo.git
```

To download this repository
```console
https://github.com/baristelmen/ENSTA-Containers/archive/refs/heads/main.zip
```
Once you have the source code, follow the steps below (Identical for each OS):

1. Unzip the folder on your computer 
2. Open you favorite terminal on your preferred OS and navigate to the unzipped folder
3. Use you favorite text editor to modify the .env file inside the source code folder (or you can leave as it is)
4. At the source code folder, execute the following command
   ```shell
   docker-compose up -d (or docker compose up -d)
5. This will download all the necessary container files on your local machine. It will take time. So make sure that you have enough coffee.
6. The jupyter lab is already installed on your computer and mildly configured. To access to your jupyter lab interface, open your favorite browser and type the address as below
   ```shell
   http://localhost:8888/lab
7. When the password is prompted, write **ENSTA-MS201**
8. Inside Jupyter Lab, you have access to a rich Python environment with SciPy and MFront pre-installed. You can create and run Jupyter notebooks, perform data analysis, and use MFront for modeling and simulations.
9. The data interaction between container and the your computer is made via data folder. You can always access to your data from this folder including your simulations results or your custom python codes.

## Contributing
Contributions to this repository are welcome! If you encounter issues or have improvements to suggest, please feel free to open an issue or submit a pull request.

## License
This repository is open-source and distributed under the MIT License. You are free to use, modify, and distribute it according to the terms of the license.
