project "Premake"
	kind "Utility"

	targetdir (outputBinDir)
	objdir (outputObjDir)

	files
	{
		"%{wks.location}/**premake5.lua"
	}

	postbuildmessage "Regenerating project files with Premake5!"

	postbuildcommands
	{
		"%{prj.location}bin/premake5 %{_ACTION} --file=\"%{wks.location}premake5.lua\""
	}
