using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LogicOptionMenu : LogicMenu
{
    [SerializeField] Button soungButton = null;
	[SerializeField] Button controlButton = null;

	protected override void Awake()
	{
		base.Awake();

		soungButton.onClick.AddListener(SoungMenu);
		controlButton.onClick.AddListener(ControlMenu);
	}

	void Start()
    {
		switchPanel = hud.AllSwitchPanel[typeMenu];

	}

    void Update()
    {
        
    }
	private void SoungMenu()
	{

	}

	private void ControlMenu()
	{

	}
}
