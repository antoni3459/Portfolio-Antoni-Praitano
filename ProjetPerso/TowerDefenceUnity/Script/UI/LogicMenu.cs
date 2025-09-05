using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LogicMenu : MonoBehaviour
{
	protected HUD hud = null;
	protected SwitchPanel switchPanel = null;
	[SerializeField] protected ETYPE_MENU typeMenu;
	
	public SwitchPanel Switch => switchPanel;

	protected virtual void Awake()
	{
		hud = HUD.Instance;
	}
}
