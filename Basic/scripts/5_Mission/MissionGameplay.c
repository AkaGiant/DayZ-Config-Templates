modded class MissionGameplay extends MissionBase
{

	void MissionGameplay() {
		GetRPCManager().AddRPC(TemplateConstants.CFG_RPC_NAMESPACE, TemplateConstants.CFG_RPC_FUNCTION, this, SingeplayerExecutionType.Both);
	}
	
	override void OnMissionStart() {
		super.OnMissionStart();
		Print(TemplateConstants.CFG_LOG_PREFIX + "[Client] Requesting Settings From Server");
		GetRPCManager().SendRPC(TemplateConstants.CFG_RPC_NAMESPACE, TemplateConstants.CFG_RPC_FUNCTION, new Param1<TemplateConfig>(NULL), true, NULL);
	}
	
	void RPCTemplateSettings(CallType type,  ParamsReadContext ctx, PlayerIdentity sender, Object target) {
		Param1<TemplateConfig> data 
		if (!ctx.Read(data)) return;
		m_TemplateConfig = data.param1;
		Print(TemplateConstants.CFG_LOG_PREFIX + "[Client] Settings Received");
	}
}