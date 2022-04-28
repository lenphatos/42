while (true) do
	service telegraf status
	if [ $? != 0 ]
	then
		service telegraf restart
	fi
	service grafana status
	if [ $? != 0 ]
        then
	 /usr/sbin/grafana-server --config=/etc/grafana.ini --homepath=/usr/share/grafana
        fi

done
