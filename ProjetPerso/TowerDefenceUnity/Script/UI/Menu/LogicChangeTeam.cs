using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LogicChangeTeam : MonoBehaviour
{
    [SerializeField] ChangeTeam button = null;
    [SerializeField] StatTempInventory inventory = null;
    [SerializeField] Transform gridInventory = null;
    [SerializeField] Transform gridTeam = null;

    List<Mob> teamList;
    List<ChangeTeam> inventoryButton = new();

	void Start()
    {
        GenerateTab();
	}

    void GenerateTab()
    {
        ClearTab();

		int _num = inventory.ListMob.Count;
		for (int i = 0; i < _num; i++)
        {
            Mob _mob = inventory.ListMob[i];

			ChangeTeam _button = Instantiate(button, gridInventory);
			_button.Init(_mob.NameMob, _mob, () => InsertTeam(_mob, _button));
			inventoryButton.Add(_button);
		}
    }

    void ClearTab()
    {
        int _count = gridInventory.childCount;
        for (int i = 0; i < _count; i++) 
			Destroy(gridInventory.GetChild(i).gameObject);
	}

    void InsertTeam(Mob _mob, ChangeTeam _button)
    {
		_button.CanEnableButton(false);

		ChangeTeam _mobButton = Instantiate(button, gridTeam);
        _mobButton.Init(_mob.NameMob, _mob, ()=> DisableMobInTeam(_mob, _mobButton));

    }
    void DisableMobInTeam(Mob _mob, ChangeTeam _button)
    {
        for (int i = 0; i < inventoryButton.Count; i++)
            if (inventoryButton[i].NameMob == _mob.NameMob)
                inventoryButton[i].CanEnableButton(true);
        Destroy(_button.gameObject);

	}
}
