using System;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class LogicLogin : LogicMenu
{
    [SerializeField] Button signUpButton = null;
    [SerializeField] Button loginButton = null;
    [SerializeField] TMP_InputField userNameInput = null;
    [SerializeField] TMP_InputField passwordInput = null;
	[SerializeField] TMP_Text textError = null;

	protected override  void Awake()
	{
		base.Awake();
	}
	void Start()
    {
		switchPanel = hud.AllSwitchPanel[typeMenu];
		signUpButton.onClick.AddListener(SignUpPlayer);
		loginButton.onClick.AddListener(LoginPlayer);
	}

	private void SignUpPlayer()
	{
		DataFire.Instance.SignUpNewPlayer(userNameInput.text, passwordInput.text, IsNewPlayer);

	}

	private void LoginPlayer()
	{
		DataFire.Instance.LoginPlayer(userNameInput.text, passwordInput.text, SetMainMenu);
	}

	void IsNewPlayer(bool _result)
	{
		if (_result)
			textError.text = "Compte créé";
		else
			textError.text = "User Name déjà pris";
	}

	void SetMainMenu(bool _isSuccess)
	{
		if (_isSuccess)
			switchPanel.SetNewPanel(1);
		else
			textError.text = "mot de passe ou user name faux";
	}
}
