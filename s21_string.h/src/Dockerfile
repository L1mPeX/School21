FROM alpine:3.20

RUN apk update && \
    apk add build-base clang17-extra-tools cppcheck make check-dev subunit-dev lcov python3 py3-pip gzip

RUN python3 -m pip install --break-system-packages gcovr

WORKDIR /app
COPY . .

RUN ln -s /app/tests /app/../tests || true 

CMD make retest && make gcov_report && echo "Report generated at report/index.html"