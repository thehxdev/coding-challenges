{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
    # nativeBuildInputs is usually what you want -- tools you need to run
    nativeBuildInputs = with pkgs.buildPackages; [
        gcc
        glibc
        gnumake
        gdb
        valgrind
        #radare2
        ccls
    ];
}
