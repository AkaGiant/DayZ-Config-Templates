modded class MissionServer extends MissionBase
{
	
	// Change "TemplateConstants" to the name of your mod's constants class
	// Change "TemplateConfig" to the name of your mod's config class
	// Change "GetTemplateConfig" to the name of your mod's config getter function

	override void OnInit() {
		super.OnInit();
		Print(TemplateConstants.CFG_LOG_PREFIX + " OnInit");
		GetTemplateConfig();
		GetRPCManager().AddRPC(TemplateConstants.CFG_RPC_NAMESPACE, TemplateConstants.CFG_RPC_FUNCTION, this, SingeplayerExecutionType.Both);
	}
	
	void TemplateSettings(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target) {
		PlayerIdentity RequestedBy = PlayerIdentity.Cast(sender);
		if (RequestedBy) {
			GetRPCManager().SendRPC(TemplateConstants.CFG_RPC_NAMESPACE, TemplateConstants.CFG_RPC_FUNCTION, new Param1<TemplateConfig>(GetTemplateConfig()), true, RequestedBy);
		}
	}
}