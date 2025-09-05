using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum ETYPE_MENU
{
    DEFAULT,
    MAIN_MENU,
    PLAY_MENU,
    ITEM_MENU,
    MAP_MENU,
}

public class HUD : Singleton<HUD>
{
    CustomDico<ETYPE_MENU, SwitchPanel> allSwitchPanel = new();

    public CustomDico<ETYPE_MENU, SwitchPanel> AllSwitchPanel => allSwitchPanel;

	public void AddSwitchPanel(ETYPE_MENU _eTypeMenu, SwitchPanel _switchPanel)
    {        
		allSwitchPanel.Add(_eTypeMenu, _switchPanel);
	}
}
