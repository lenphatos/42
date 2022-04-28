#!/bin/sh
openrc
touch /run/openrc/softlevel

while (true) do
	service telegraf status
	if [ $? != 0 ]
	then
		service telegraf restart
	fi

	service influxdb status
        if [ $? != 0 ]
        then
		service influxdb restart
        fi
done

