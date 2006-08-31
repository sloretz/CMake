/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef cmInstallTargetsCommand_h
#define cmInstallTargetsCommand_h

#include "cmCommand.h"

/** \class cmInstallTargetsCommand
 * \brief Specifies where to install some targets
 *
 * cmInstallTargetsCommand specifies the relative path where a list of
 * targets should be installed. The targets can be executables or
 * libraries.  
 */
class cmInstallTargetsCommand : public cmCommand
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  virtual cmCommand* Clone() 
    {
    return new cmInstallTargetsCommand;
    }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  virtual bool InitialPass(std::vector<std::string> const& args);

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  virtual const char* GetName() { return "INSTALL_TARGETS";}

  /**
   * Succinct documentation.
   */
  virtual const char* GetTerseDocumentation() 
    {
    return "Old installation command.  Use the INSTALL command.";
    }
  
  /**
   * More documentation.
   */
  virtual const char* GetFullDocumentation()
    {
    return
      "This command has been superceded by the INSTALL command.  It "
      "is provided for compatibility with older CMake code.\n"
      "  INSTALL_TARGETS(<dir> [RUNTIME_DIRECTORY dir] target target)\n"
      "Create rules to install the listed targets into the given directory.  "
      "The directory <dir> is relative to the installation prefix, which "
      "is stored in the variable CMAKE_INSTALL_PREFIX. If RUNTIME_DIRECTORY "
      "is specified, then on systems with special runtime files "
      "(Windows DLL), the files will be copied to that directory.";
    }
  
  /** This command is only kept for compatibility with older CMake versions. */
  virtual bool IsDiscouraged()
    {
    return true;
    }

  cmTypeMacro(cmInstallTargetsCommand, cmCommand);
};


#endif
