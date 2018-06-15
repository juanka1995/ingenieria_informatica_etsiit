#!/bin/bash
find ~ -maxdepth 1 > listahome-`date +%Y-%j-%T-$$`
