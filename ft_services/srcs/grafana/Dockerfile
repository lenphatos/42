FROM alpine

# Add and run .sh 
ADD srcs/init.sh /tmp/init.sh
RUN sh /tmp/init.sh && rm -f /tmp/init.sh

# Add others files
ADD srcs/start.sh /tmp/
ADD srcs/telegraf.conf /etc/telegraf.conf
ADD srcs/data_source.yaml /usr/share/grafana/conf/provisioning/datasources
ADD srcs/dashboard.yaml /usr/share/grafana/conf/provisioning/dashboards

# Expose Ports
EXPOSE 3000

# Start
CMD sh /tmp/start.sh
