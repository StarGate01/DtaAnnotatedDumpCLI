# DtaAnnotatedDumpCLI

CLI tool to invoke sedutil DtaAnnotatedDump. This tool parses a TCG OPAL SCSI command or response buffer.

## Building

Make sure you have `gcc`, `cmake` and `make`.

```
mkdir -p build
cd build
cmake ..
make -j$(nproc)
```

## Usage

```
Usage: ./build/src/DtaAnnotatedDumpCLI <file_name> <cmd>
cmd options: IF_RECV, IF_SEND, IDENTIFY
```
