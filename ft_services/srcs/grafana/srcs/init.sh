apk update
apk add --no-cache --upgrade bash
apk add openrc --no-cache
apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache
apk add grafana --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache


mkdir -p /etc/grafana/provisioning/dashboards

openrc
touch /run/openrc/softlevel
