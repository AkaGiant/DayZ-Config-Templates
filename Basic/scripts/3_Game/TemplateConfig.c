class TemplateConfig // This should match the file name
{

	private static string PROFILE = "$profile:Basic";
	private static string CONFIG = PROFILE + "/config.json";

	// DEFAULT VALUES, CAN BE CHANGED IN THE GENERATED CONFIG FILE
	
	// Definitions:
	// String: string variableName = "value";
	// Array: ref array<string> variableName = {"value1", "value2"}; // Arrays can contain any variable type, but for this example we use strings
	// int: int variableName = 0; // 0 is the default value, can be changed to any integer *any FULL number*
	// float: float variableName = 0.0; // 0.0 is the default value, can be changed to any float *any number with a decimal point*
	// bool: bool variableName = false; // false is the default value, can be changed to true or false

	// Conditionals
	string CraftNailsName = "Craft Nails"; // Name of the recipe, can be changed to any string
	bool isInstaRecipe = false; // True or false, should this recipe be performed instantly without animation
	float animationLength = 0.5; // Animation length in relative time units, 0.5 means half a second
	float specialty = -0.01; // Value > 0 for roughness, value < 0 for precision
	
	// Ingredient 1;
	ref array<string> ingredients1 = {"PipeWrench", "Pipe"};
	int addHealthIngredient1 = 0; // 0 = do nothing
	int setHealthIngredient1 = -1; // -1 = do nothing
	int addQuantityIngredient1 = 0; // 0 = do nothing
	bool destroyIngredient1 = true; // true = destroy, false = do nothing
	bool useSoftSkillsIngredient1 = false; // set 'true' to allow modification of the values by softskills on this ingredient
	
	int minDamageIngredient1 = -1; // -1 = disable check
	int maxDamageIngredient1 = -1; // -1 = disable check
	int minQuantityIngredient1 = -1; // -1 = disable check
	int maxQuantityIngredient1 = -1; // -1 = disable check


	// Ingredient 2;
	ref array<string> ingredients2 = {"Handsaw", "Hacksaw"};
	int addHealthIngredient2 = -7; // How much health to add to the ingredient
	int setHealthIngredient2 = -1; // -1 = do nothing
	int addQuantityIngredient2 = 0; // 0 = do nothing
	bool destroyIngredient2 = false; // false = do nothing
	bool useSoftSkillsIngredient2 = false; // set 'true' to allow modification of the values by softskills on this ingredient
	int minDamageIngredient2 = -1; // -1 = disable check
	int maxDamageIngredient2 = -1; // -1 = disable check

	int minQuantityIngredient2 = -1; // -1 = disable check
	int maxQuantityIngredient2 = -1; // -1 = disable check

	// Result
	string result = "Nail"; 
	bool setFullQuantityResult = false; 
	int setQuantityResult = 40;
	int setHealthResult = -1;
	int inheritsHealthResult = -1; 
	int inheritsColorResult = -1; 
	int toInventoryResult = -2; 
	int replacesIngredientResult = -1; 
	bool useSoftSkillsResult = false;
	
	// Load config file or create default file if config doesn't exist
	// Don't change
	void Load() {
		if (GetGame().IsServer()) {
			if (!FileExist(PROFILE)) MakeDirectory(PROFILE);

			if (FileExist(CONFIG)) JsonFileLoader<TemplateConfig>.JsonLoadFile(CONFIG, this);
			else Save();
		}		
		else Print(TemplateConstants.CFG_LOG_PREFIX + " Trying to load settings before they were received by the server.");
	}
	
	void Save() {
		JsonFileLoader<TemplateConfig>.JsonSaveFile(CONFIG, this);
	};
}

// Change "TemplateConfig" to the name of your mod's config class
ref TemplateConfig m_TemplateConfig;
static TemplateConfig GetTemplateConfig()
{
	if (!m_TemplateConfig)
	{
		Print(TemplateConstants.CFG_LOG_PREFIX + " Init");
		m_TemplateConfig = new TemplateConfig;
		m_TemplateConfig.Load();
	}
	return m_TemplateConfig;
};