#!/bin/bash
set -e

# ---------- 設定 ----------
CXX="g++"
HEADER_ROOT="./cp_templates"

# デフォルトのオプション（普段のものをベースに）
CXXFLAGS_DEFAULT="-O2 -g -std=c++2a -Wall -Wextra -Wshadow -Wfloat-equal -fsanitize=undefined,address -ftrapv -DLOCAL"

# 引数でオプションを上書きできるように
CXXFLAGS="${1:-$CXXFLAGS_DEFAULT}"

echo "🔧 Compiler:    $CXX"
echo "📁 Header root: $HEADER_ROOT"
echo "⚙️  Flags:       $CXXFLAGS"
echo

# ---------- GCH 作成 ----------
find "$HEADER_ROOT" -type f -name "*.hpp" \
| grep -v "geometry/util\.hpp" \
| grep -v "math/formal_power_series\.hpp" \
| while read -r header; do
    echo "[*] Compiling: $header"
    "$CXX" -x c++-header $CXXFLAGS "$header" -o "$header.gch"
done

echo
echo "✅ All .gch files generated."
