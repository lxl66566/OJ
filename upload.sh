#!/usr/bin/env bash
git add -A
git commit -m $(date "+%Y%m%d-%H:%M:%S")
git push origin main