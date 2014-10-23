#!/bin/bash
set -e

cd tests

rm -rf Export

expect -c "
spawn haxelib run duell build android -test -verbose -overridebranch master

set timeout -1

expect {
	\"is not currently installed.\" {

		send \"y\r\"

		exp_continue
	}
	\"is missing,\" {

		send \"y\r\"

		exp_continue
	}
	\"not up to date\" {

		send \"y\r\"

		exp_continue
	}
}
"





