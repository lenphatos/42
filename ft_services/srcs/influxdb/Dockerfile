FROM alpine:latest

# We install packages
RUN apk update && apk add influxdb \
&& apk add bash openrc --no-cache --upgrade
RUN apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache

EXPOSE 8086

VOLUME ["/var/lib/influxdb"]

# Telegraf setup
RUN rm /etc/telegraf.conf
ADD srcs/telegraf.conf /etc/telegraf.conf

ADD srcs/start.sh /tmp/

# Start .sh
CMD sh /tmp/start.sh

