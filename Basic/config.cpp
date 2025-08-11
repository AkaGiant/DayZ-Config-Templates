class CfgPatches
{
	class BasicTemplateConfig // Change this to the name of your mod
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};
class CfgMods
{
	class DayZConfigTemplates // Change this to the name of your mod
	{
		dir="DayZConfigTemplates\Basic"; // Change this to the path of your mod
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="Basic Template Config"; // Change this to the name of your mod
		credits="AkaGiant";
		author="AkaGiant"; // Change this to the author of your mod
		authorID="0";
		version="1.0";  // Change this to the version of your mod
		extra=0;
		type="mod";
		dependencies[] = {"Game", "World", "Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"DayZConfigTemplates\Basic\scripts\3_Game"}; // Change this to the path of your scripts
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"DayZConfigTemplates\Basic\scripts\4_World"}; // Change this to the path of your scripts
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"DayZConfigTemplates\Basic\scripts\5_Mission"}; // Change this to the path of your scripts
			};
		};
	};
};

