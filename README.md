
## Reproducing my zephyr module problem

The problem I am having is pulling in an external module.

The cJSON module created by Nordic is at https://github.com/nrfconnect/sdk-cjson

Nordic's are pulling this in to their SDK (in newer commits) via west:

```
    - name: cjson
      revision: 50bddddf7fb45e4ce87bc3619df06db55d181856
      remote: nrf
      repo-path: sdk-cjson
      path: modules/lib/cjson
```

This looks like a standard pattern to pull in a module. They then have some OS hooks in the modules/cjson folder of the SDK, which I've replicated in this repro.

The problem, when cmake prepares the build system, it errors out (see logs below).
So my question is, have I missed something obvious. Or have Nordic done something with their SDK / Zephyr fork that adds some special sauce?

To run this repro, create a new directory (e.g. zephyrrepro) and

```
west init -m https://github.com/Ideacraftteam/zephyrrepro app
west update

```
and build.


## Error Logs

```

sandbox/zephyrrepro/app via △ v3.19.7
➜ west build -p -b nrf52840dk_nrf52840
-- west build: making build dir /Users/damian/Code/sandbox/zephyrrepro/app/build pristine
-- west build: generating a build system
Including boilerplate (Zephyr base): /Users/damian/Code/sandbox/zephyrrepro/zephyr/cmake/app/boilerplate.cmake
-- Application: /Users/damian/Code/sandbox/zephyrrepro/app
-- Zephyr version: 2.6.0 (/Users/damian/Code/sandbox/zephyrrepro/zephyr), build: zephyr-v2.6.0
-- Found Python3: /Users/damian/.pyenv/versions/3.9.1/bin/python3.9 (found suitable exact version "3.9.1") found components: Interpreter
-- Found west (found suitable version "0.10.1", minimum required is "0.7.1")
-- Board: nrf52840dk_nrf52840
-- Cache files will be written to: /Users/damian/Library/Caches/zephyr
-- Found toolchain: gnuarmemb (/opt/nordic/ncs/v1.5.1/toolchain)
-- Found BOARD.dts: /Users/damian/Code/sandbox/zephyrrepro/zephyr/boards/arm/nrf52840dk_nrf52840/nrf52840dk_nrf52840.dts
-- Found devicetree overlay: /Users/damian/Code/sandbox/zephyrrepro/app/boards/nrf52840dk_nrf52840.overlay
-- Generated zephyr.dts: /Users/damian/Code/sandbox/zephyrrepro/app/build/zephyr/zephyr.dts
-- Generated devicetree_unfixed.h: /Users/damian/Code/sandbox/zephyrrepro/app/build/zephyr/include/generated/devicetree_unfixed.h
-- Generated device_extern.h: /Users/damian/Code/sandbox/zephyrrepro/app/build/zephyr/include/generated/device_extern.h
Parsing /Users/damian/Code/sandbox/zephyrrepro/app/Kconfig
/Users/damian/Code/sandbox/zephyrrepro/zephyr/scripts/kconfig/kconfig.py: /Users/damian/Code/sandbox/zephyrrepro/app/build/Kconfig/Kconfig.modules:2: Could not open '/Users/damian/Code/sandbox/zephyrrepro/zephyr/' (in 'osource "$(ZEPHYR_CJSON_KCONFIG)"') (EISDIR: Is a directory)
CMake Error at /Users/damian/Code/sandbox/zephyrrepro/zephyr/cmake/kconfig.cmake:264 (message):
  command failed with return code: 1
Call Stack (most recent call first):
  /Users/damian/Code/sandbox/zephyrrepro/zephyr/cmake/app/boilerplate.cmake:565 (include)
  /Users/damian/Code/sandbox/zephyrrepro/zephyr/share/zephyr-package/cmake/ZephyrConfig.cmake:24 (include)
  /Users/damian/Code/sandbox/zephyrrepro/zephyr/share/zephyr-package/cmake/ZephyrConfig.cmake:35 (include_boilerplate)
  CMakeLists.txt:15 (find_package)

  ```
