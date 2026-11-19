# Works around the Windows 32 KB command-line limit on the ESP32-C6 (RISC-V) build.
#
# PlatformIO hands g++ a response file, but riscv32-esp-elf-gcc then re-expands every -I flag
# onto the command line it uses to start `as`. Arduino-ESP32 3.1.0 has ~300 framework include
# dirs, so that line is ~34 KB and CreateProcess fails ("cannot execute ... as.exe: No such
# file or directory").
#
# Fix: emit framework include dirs as one `-iprefix <libs>/include/` plus short
# `-iwithprefixbefore <rel>` entries. cc1/cc1plus treat these exactly like -I (same chain, same
# command-line order), and gcc doesn't forward them to the assembler.
import re

from SCons.PathList import PathList

Import("env")  # noqa: F821  (SCons global)

_LIBS_INCLUDE = re.compile(r"^(.*framework-arduinoespressif32-libs/[^/]+/include/)(.+)$")


def _short_incs(paths, env, rdirs, target=None, source=None):
    flags = []
    prefix = None
    for node in env.Flatten(rdirs(PathList(paths).subst_path(env, target, source))):
        p = node.abspath.replace("\\", "/") if hasattr(node, "abspath") else str(node)
        m = _LIBS_INCLUDE.match(p)
        if m and (prefix is None or prefix == m.group(1)):
            if prefix is None:
                prefix = m.group(1)
                flags += ["-iprefix", prefix]
            flags += ["-iwithprefixbefore", m.group(2)]
        else:
            flags.append("-I" + p)
    return flags


env["_short_incs"] = _short_incs  # noqa: F821
env["_CPPINCFLAGS"] = "$( ${_short_incs(CPPPATH, __env__, RDirs, TARGET, SOURCE)} $)"  # noqa: F821
