FROM alpine:latest

RUN apk update \
&& apk add vsftpd && apk add bash openrc openssl curl \
&& apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache

ADD /srcs/vsftpd.conf		/etc/vsftpd/vsftpd.conf
ADD /srcs/setup.sh		/tmp/setup.sh
ADD /srcs/livenessprobe.sh	/srcs/livenessprobe.sh

RUN rm /etc/telegraf.conf
ADD /srcs/telegraf.conf /etc/

RUN openssl req -x509 -nodes -subj '/C=FR/ST=PARIS/L=PARIS/O=jereligi/CN=localhost' \
		-days 365 -newkey rsa:2048 -keyout /etc/ssl/private/vsftpd.key \
		 -out /etc/ssl/certs/vsftpd.crt

EXPOSE 21 21000-21010

CMD sh /tmp/setup.sh
