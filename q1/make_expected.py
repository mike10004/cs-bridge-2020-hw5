#!/usr/bin/env python3

import sys
import json

def main():
    cases = []
    for n in [1, 2, 3, 7, 10]:
        rows = []
        for i in range(1, n + 1):
            cols = []
            for j in range(1, n + 1):
                cols.append(str(i * j))
            row = "\t".join(cols)
            rows.append(row)
        s = "\n".join(rows)
        cases.append((n, s))
    print(json.dumps(cases, indent=2))
    return 0


if __name__ == '__main__':
    exit(main())
