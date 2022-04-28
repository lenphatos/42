FROM alpine

# Add files
ADD srcs/init.sh ./
ADD srcs/nginx.conf /etc/nginx/nginx.conf
ADD srcs/telegraf.conf ./etc/
ADD srcs/start.sh /tmp/
ADD srcs/sshd_config /tmp/
# Expose Ports
EXPOSE 80 443 22

# start sh
RUN sh ./init.sh

RUN apk update && apk add --no-cache supervisor
COPY srcs/supervisord.conf /etc/supervisord.conf
CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
