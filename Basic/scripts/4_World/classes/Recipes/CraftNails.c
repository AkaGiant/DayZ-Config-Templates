class CraftNails extends RecipeBase
{	
	override void Init()
	{
		m_Name = GetTemplateConfig().CraftNailsName;
		m_IsInstaRecipe = GetTemplateConfig().isInstaRecipe;
		m_AnimationLength = GetTemplateConfig().animationLength;
		m_Specialty = GetTemplateConfig().specialty;
		
		// Conditions
		m_MinDamageIngredient[0] = GetTemplateConfig().minDamageIngredient1;
		m_MaxDamageIngredient[0] = GetTemplateConfig().maxDamageIngredient1;
		
		m_MinQuantityIngredient[0] = GetTemplateConfig().maxQuantityIngredient1;
		m_MaxQuantityIngredient[0] = GetTemplateConfig().maxQuantityIngredient1;
		
		m_MinDamageIngredient[1] = GetTemplateConfig().maxDamageIngredient2;
		m_MaxDamageIngredient[1] = GetTemplateConfig().maxDamageIngredient2;
		
		m_MinQuantityIngredient[1] = GetTemplateConfig().maxQuantityIngredient2;
		m_MaxQuantityIngredient[1] = GetTemplateConfig().maxQuantityIngredient2;

		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS

		// Ingredient 1
		insertIngredient(0, GetTemplateConfig().ingredients1);
		m_IngredientAddHealth[0] = GetTemplateConfig().addHealthIngredient1;
		m_IngredientSetHealth[0] = GetTemplateConfig().setHealthIngredient1; 
		m_IngredientAddQuantity[0] = GetTemplateConfig().addQuantityIngredient1;
		m_IngredientDestroy[0] = GetTemplateConfig().destroyIngredient1;
		m_IngredientUseSoftSkills[0] = GetTemplateConfig().useSoftSkillsIngredient1;
		
		//----------------------------------------------------------------------------------------------------------------------

		// Ingredient 2
		insertIngredient(1, GetTemplateConfig().ingredients2);
		m_IngredientAddHealth[1] = GetTemplateConfig().addHealthIngredient2;
		m_IngredientSetHealth[1] = GetTemplateConfig().setHealthIngredient2; 
		m_IngredientAddQuantity[1] = GetTemplateConfig().addQuantityIngredient2;
		m_IngredientDestroy[1] = GetTemplateConfig().destroyIngredient2;
		m_IngredientUseSoftSkills[1] = GetTemplateConfig().useSoftSkillsIngredient2;

		//----------------------------------------------------------------------------------------------------------------------
		
		// Result 1
		AddResult(GetTemplateConfig().result); 
		m_ResultSetFullQuantity[0] = GetTemplateConfig().setFullQuantityResult;
		m_ResultSetQuantity[0] = GetTemplateConfig().setQuantityResult;
		m_ResultSetHealth[0] = GetTemplateConfig().setHealthResult;
		m_ResultInheritsHealth[0] = GetTemplateConfig().inheritsHealthResult;
		m_ResultInheritsColor[0] = GetTemplateConfig().inheritsColorResult;
		m_ResultToInventory[0] = GetTemplateConfig().toInventoryResult;
		m_ResultUseSoftSkills[0] = GetTemplateConfig().useSoftSkillsResult;
		m_ResultReplacesIngredient[0] = GetTemplateConfig().replacesIngredientResult;
	}

	void insertIngredient(int index, array<string> ingredients) {
		if (!ingredients || ingredients.Count() == 0) {
			Print("CraftNails: No ingredients provided for index " + index);
			return;
		}
		for (int i = 0; i < ingredients.Count(); i++) {
			InsertIngredient(index, ingredients[i]);
		}
	}

	// Don't change
	override bool CanDo(ItemBase ingredients[], PlayerBase player) { return true; }
	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		Debug.Log("Recipe Do method called","recipes");
	}
};
