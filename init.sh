#!/bin/bash

# readline 디렉터리로 이동
cd readline

# configure 스크립트 실행
if ./configure; then
    echo "configure 성공"
else
    echo "configure 실패"
    exit 1
fi

# 상위 디렉터리로 이동
cd ..

# make 명령 실행
if make; then
    echo "make 성공"
else
    echo "make 실패"
    exit 1
fi

