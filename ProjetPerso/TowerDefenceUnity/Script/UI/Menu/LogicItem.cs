using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LogicItem : LogicMenu
{
    [SerializeField] Button saleTurellButton = null;
    [SerializeField] Button updateButton = null;

	protected override void Awake()
	{
		base.Awake();
	}
	void Start()
    {
        switchPanel = hud.AllSwitchPanel[typeMenu];
		saleTurellButton.onClick.AddListener(SaleTurell);
		updateButton.onClick.AddListener(UpdatePlayer);

	}

	private void UpdatePlayer()
	{

	}

	private void SaleTurell()
	{

	}
}
