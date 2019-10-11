#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

TTND=${TTND:-$SRCDIR/titancoind}
TTNCLI=${TTNCLI:-$SRCDIR/titancoin-cli}
TTNTX=${TTNTX:-$SRCDIR/titancoin-tx}
TTNQT=${TTNQT:-$SRCDIR/qt/titancoin-qt}

[ ! -x $TTND ] && echo "$TTND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
TTNVER=($($TTNCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for titancoind if --version-string is not set,
# but has different outcomes for titancoin-qt and titancoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$TTND --version | sed -n '1!p' >> footer.h2m

for cmd in $TTND $TTNCLI $TTNTX $TTNQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${TTNVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${TTNVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
