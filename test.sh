#!/bin/bash

echo "=== ADDITION TESTS ==="
echo "Input: 123 + 456 | Expected: 579"
../apc 123 + 456
echo ""
echo "Input: -123 + -456 | Expected: -579"
../apc -123 + -456
echo ""
echo "Input: 500 + -200 | Expected: 300"
../apc 500 + -200
echo ""
echo "Input: 200 + -500 | Expected: -300"
../apc 200 + -500
echo ""
echo "Input: 999 + 1 | Expected: 1000 (carry propagation)"
../apc 999 + 1
echo ""
echo "Input: 0 + 0 | Expected: 0"
../apc 0 + 0
echo ""
echo "Input: 123456789 + 987654321 | Expected: 1111111110 (large numbers)"
../apc 123456789 + 987654321
echo ""

echo "=== SUBTRACTION TESTS ==="
echo "Input: 500 - 200 | Expected: 300"
../apc 500 - 200
echo ""
echo "Input: 200 - 500 | Expected: -300"
../apc 200 - 500
echo ""
echo "Input: 123 - -456 | Expected: 579"
../apc 123 - -456
echo ""
echo "Input: -123 - 456 | Expected: -579"
../apc -123 - 456
echo ""
echo "Input: 1000 - 1 | Expected: 999 (borrow propagation)"
../apc 1000 - 1
echo ""
echo "Input: 100 - 100 | Expected: 0"
../apc 100 - 100
echo ""
echo "Input: -123 - -456 | Expected: 333"
../apc -123 - -456
echo ""
echo "Input: 0 - 100 | Expected: -100"
../apc 0 - 100
echo ""

echo "=== MULTIPLICATION TESTS ==="
echo "Input: 12 x 13 | Expected: 156"
../apc 12 x 13
echo ""
echo "Input: -12 x -13 | Expected: 156"
../apc -12 x -13
echo ""
echo "Input: 12 x -13 | Expected: -156"
../apc 12 x -13
echo ""
echo "Input: -12 x 13 | Expected: -156"
../apc -12 x 13
echo ""
echo "Input: 0 x 100 | Expected: 0"
../apc 0 x 100
echo ""
echo "Input: 1 x 999 | Expected: 999"
../apc 1 x 999
echo ""
echo "Input: 111 x 111 | Expected: 12321"
../apc 111 x 111
echo ""
echo "Input: 123 x 456 | Expected: 56088"
../apc 123 x 456
echo ""
echo "Input: 999 x 999 | Expected: 998001"
../apc 999 x 999
echo ""

echo "=== DIVISION TESTS ==="
echo "Input: 156 / 12 | Expected: 13"
../apc 156 / 12
echo ""
echo "Input: -156 / -12 | Expected: 13"
../apc -156 / -12
echo ""
echo "Input: 156 / -12 | Expected: -13"
../apc 156 / -12
echo ""
echo "Input: -156 / 12 | Expected: -13"
../apc -156 / 12
echo ""
echo "Input: 100 / 1 | Expected: 100"
../apc 100 / 1
echo ""
echo "Input: 100 / 100 | Expected: 1"
../apc 100 / 100
echo ""
echo "Input: 50 / 100 | Expected: 0 (dividend < divisor)"
../apc 50 / 100
echo ""
echo "Input: 1000 / 10 | Expected: 100"
../apc 1000 / 10
echo ""
echo "Input: 999 / 3 | Expected: 333"
../apc 999 / 3
echo ""

echo "=== EDGE CASES ==="
echo "Input: 0 + 0 | Expected: 0"
../apc 0 + 0
echo ""
echo "Input: 0 - 0 | Expected: 0"
../apc 0 - 0
echo ""
echo "Input: 0 x 0 | Expected: 0"
../apc 0 x 0
echo ""
echo "Input: 100 / -1 | Expected: -100"
../apc 100 / -1
echo ""
echo "Input: -100 / -1 | Expected: 100"
../apc -100 / -1
echo ""

echo "=== LARGE NUMBER TESTS ==="
echo "Input: 123456789 x 2 | Expected: 246913578"
../apc 123456789 x 2
echo ""
echo "Input: 1000000000 + 1000000000 | Expected: 2000000000"
../apc 1000000000 + 1000000000
echo ""
echo "Input: 9999999999 + 1 | Expected: 10000000000"
../apc 9999999999 + 1
echo ""
echo "Input: 100000 / 5 | Expected: 20000"
../apc 100000 / 5
echo ""

echo "=== ALL TESTS COMPLETED ==="
