## A base image for general usage for other containers
## It is not intended for production usage but serve as only a base image
## for other containers

## For more information and bug reporting -> baristelmen@gmail.com

ARG OWNER="Baris Telmen"
ARG UBUNTU_VERSION=22.04
FROM baristelmen/jupyter-scipy-notebook:1.0

LABEL maintainer="Baris TELMEN (baristelmen@gmail.com)"
LABEL description="Foundation of jupyter notebook images"

ARG NB_USER="boltzmann"
ARG NB_UID="1005"
ARG NB_GID="1005"

## Docker configuration for package installation
SHELL ["/bin/bash", "-o", "pipefail", "-c"]
USER root

## Update and upgrade packages
RUN upgrade_packages

RUN install_packages cmake git gcc gfortran g++ gnuplot

## Arguments for application
ARG APP_NAME=tfel
ARG APP_VERSION=4.1.0
ARG SOURCE=https://github.com/thelfer/tfel/archive/refs/tags/TFEL-${APP_VERSION}.tar.gz
ARG SOURCE_DIR=/apps/source
ARG BINARY_DIR=/apps/binary
ARG APP_SOURCE_DIR=${SOURCE_DIR}/${APP_NAME}
ARG APP_BINARY_DIR=${BINARY_DIR}/${APP_NAME}/${APP_VERSION}

## Create base directories for apps
RUN mkdir -p /apps/{source,binary}
RUN mkdir -p /apps/source/${APP_NAME}
RUN mkdir -p /apps/binary/${APP_NAME}/${APP_VERSION}

RUN echo wget -O ${APP_VERSION} ${SOURCE} -P /apps/source/${APP_NAME}
RUN wget -O ${APP_SOURCE_DIR}/${APP_VERSION}.tar.gz ${SOURCE}
RUN tar -xvf ${APP_SOURCE_DIR}/${APP_VERSION}.tar.gz -C ${APP_SOURCE_DIR}/
RUN mv ${APP_SOURCE_DIR}/tfel* ${APP_SOURCE_DIR}/${APP_VERSION}
RUN mkdir -p ${APP_SOURCE_DIR}/${APP_VERSION}/build

ENV PYTHON_INCLUDE_DIRS=/usr/include/python2.7 \
    PYTHON_LIBRARIES=/usr/lib/python2.7/config/libpython2.7.so

# Install Python 3 packages
RUN mamba install --yes \
    'boost'  && \
    mamba clean --all -f -y && \
    fix-permissions "${CONDA_DIR}" && \
    fix-permissions "/home/${NB_USER}"

WORKDIR ${APP_SOURCE_DIR}/${APP_VERSION}/build
RUN cmake -DPYTHON_INCLUDE_DIR=/opt/conda/include/python3.11 \
          -DPYTHON_LIBRARY=/opt/conda/lib/libpython3.11.so \
          -DCMAKE_INSTALL_PREFIX=${APP_BINARY_DIR} \
          -DCMAKE_BUILD_TYPE=Release \
          -Denable-fortran=ON \
          -Denable-python=ON \
          -Denable-python-bindings=ON \
          -Denable-numpy-support=ON \
          -Denable-java=OFF \
          -Denable-eigen=OFF \
          -Denable-mkl=OFF \
          -Denable-mfront-quantity-tests=ON \
          -Denable-testing=ON \
          -Denable-aster=ON \
          -Dlocal-castem-header=OFF \
          -Denable-abaqus=ON \
          -Denable-diana-fea=ON \
          -Denable-calculix=ON \
          -Denable-ansys=ON \
          -Denable-europlexus=ON \
          -Denable-cyrano=ON \
          -Denable-zmat=OFF \
          -Denable-castem-pleiades=ON \
          -Denable-comsol=ON \
          -Wno-dev \
          ..

RUN make -j4
RUN make install

ENV ENSTA_APP_NAME="scipy-mfront" \
    PATH="/apps/binary/tfel/4.1.0/bin:$PATH" \
    LD_LIBRARY_PATH="/apps/binary/tfel/4.1.0/lib:$LD_LIBRARY_PATH"

RUN mkdir -p /apps/binary/tfel/behaviors/

WORKDIR /apps/binary/tfel/behaviors/

COPY behaviors/ /apps/binary/tfel/behaviors/

RUN rm -rf src include && chmod +x compile.sh && ./compile.sh

COPY jupyter_server_config.py /etc/jupyter/

RUN fix-permissions /etc/jupyter/
RUN fix-permissions "/home/${NB_USER}"
RUN fix-permissions "/apps"

USER ${NB_UID}

WORKDIR "${HOME}"