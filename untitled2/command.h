/*
 * command.h
 *
 *  Created on: Sep 10, 2018
 *      Author: dgv130030
 */

#pragma once

class command
{
public:
    command() {}
    virtual ~command() {}
    virtual void execute() = 0;
    virtual void unExecute() {};
};


