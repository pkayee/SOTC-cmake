#!/bin/sh
# cc_alt.sh <cc_dir> <in.c> <out.o> <ee-gcc flags...>
# Compile one C file with a second ee-gcc (e.g. tools/cc/ee-gcc2.9-991111) the way the 2.96
# flow does with regnames.specs:
#   cc1 -S -DPREPROCESS_ASM  ->  cpp -lang-asm (expands INCLUDE_ASM and register names)  ->  as
# 2.9's driver has no %(cpp_options)/%(cc1_options) specs and does not search bin/../lib,
# so the custom spec cannot be used.
# `-$` makes cpp treat $ as punctuation so `$v1` becomes `$3`
# (2.96's cpp0 -lang-asm does this by default).

cc=$1
in=$2
out=$3
shift 3

tmp="$out.tmp$$"

cleanup() {
    rm -f "$tmp.si" "$tmp.s" "$tmp.err"
}
trap cleanup EXIT

run() {
    "$@" 2>"$tmp.err" || {
        grep -v '^time in\|^$' "$tmp.err" >&2
        exit 1
    }
    grep -v '^time in\|^$' "$tmp.err" >&2 || true
}

run "$cc/bin/ee-gcc" -S -DPREPROCESS_ASM "$@" "$in" -o "$tmp.si"
run sh -c 'exec "$0"/lib/gcc-lib/ee/*/cpp -lang-asm -\$ -I./ "$1" -o "$2"' "$cc" "$tmp.si" "$tmp.s"
run "$cc/bin/ee-gcc" -c -x assembler "$@" "$tmp.s" -o "$out"