#!/usr/bin/env bash
git add -A
git commit --allow-empty-message -m "$*"
git push origin main