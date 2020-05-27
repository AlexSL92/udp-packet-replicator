# UDP Packet Replicator

Send network UDP packets to the desired ip address and port.

## Table of Contents

- [UDP Packet Replicator](#udp-packet-replicator)
  - [Table of Contents](#table-of-contents)
  - [About The Project](#about-the-project)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Build](#build)
  - [Usage](#usage)
  - [Roadmap](#roadmap)
  - [Contributing](#contributing)
  - [License](#license)

## About The Project

The main objective of this project is to provide a simple but reliable way to send packets through the network using an UDP protocol. 

The data to be sent has to be stored in a file. The application will read it, sending the data to the desired ip address and port at the specified period.

## Getting Started

To get a local copy of the project and to run it, you can download build it from source with the following steps.

### Prerequisites

The following software is required together with a proper compiler in order to build the project.

* [cmake](https://cmake.org/download/)
* [conan](https://conan.io/downloads.html)

### Build

1. Clone the repository
```sh
git clone https://github.com/AlexSL92/udp-packet-replicator.git
```
2. Create _build_ folder inside the repository path
```sh
cd udp-packet-replicator && mkdir build && cd build
```
3. Run cmake
```sh
cmake -DCMAKE_BUILD_TYPE={BUILD_TYPE} -G "<generator-name>" ..
```
_Being {BUILD_TYPE} = Release / Debug_

Use cmake --help to get a list of [generators](https://cmake.org/cmake/help/v3.0/manual/cmake-generators.7.html)

4. Build the project using the specified generator

## Usage

Run the software using the following command.
```sh
./udp-packet-replicator -ip ADDRESS -port PORT -ms TIME -file PATH
```
* Replace ADDRESS with the desired ip address where to send packets
* Replace PORT with the desired port where to send packets
* Replace TIME with the desired interval between packets in milliseconds
* Replace PATH with the relative path to the binary data file

## Roadmap

See the [open issues](https://github.com/AlexSL92/udp-packet-replicator/issues) page of GitHub for a list of proposed features and known issues.

## Contributing

Contributions are greatly appreciated. Follow these steps to contribute to the project.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/NewFeature`)
3. Commit your Changes (`git commit -m 'Add some NewFeature'`)
4. Push to the Branch (`git push origin feature/NewFeature`)
5. Open a Pull Request

## License

Distributed under the MIT License. See `LICENSE` for more information.