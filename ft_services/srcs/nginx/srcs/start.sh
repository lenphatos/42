while (true) do
	service telegraf status
	if [ $? != 0 ]
	then
		service telegraf restart
	fi
	service nginx status
        if [ $? != 0 ]
        then
                service nginx restart
        fi
        service sshd status
        if [ $? != 0 ]
        then
                service sshd restart
        fi
done
