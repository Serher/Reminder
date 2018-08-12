object Form1: TForm1
  Left = 193
  Top = 120
  Width = 848
  Height = 318
  AlphaBlendValue = 100
  Caption = 'Reminder'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Visible = True
  OnActivate = FormActivate
  OnCreate = FormCreate
  DesignSize = (
    832
    279)
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 16
    Top = 262
    Width = 78
    Height = 13
    Anchors = [akLeft, akBottom]
    Caption = 'Osipov, 08.2017'
  end
  object Pan1: TPanel
    Left = 16
    Top = 8
    Width = 802
    Height = 249
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    DesignSize = (
      802
      249)
    object Label1: TLabel
      Left = 152
      Top = 24
      Width = 17
      Height = 20
      Caption = '->'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LE1: TLabeledEdit
      Left = 16
      Top = 24
      Width = 73
      Height = 24
      EditLabel.Width = 27
      EditLabel.Height = 15
      EditLabel.Caption = #1044#1072#1090#1072
      EditLabel.Font.Charset = RUSSIAN_CHARSET
      EditLabel.Font.Color = clBlue
      EditLabel.Font.Height = -13
      EditLabel.Font.Name = 'Times New Roman'
      EditLabel.Font.Style = [fsBold]
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      LabelPosition = lpAbove
      LabelSpacing = 3
      ParentFont = False
      TabOrder = 0
      OnDblClick = LE1DblClick
    end
    object LE2: TLabeledEdit
      Left = 96
      Top = 24
      Width = 41
      Height = 24
      EditLabel.Width = 36
      EditLabel.Height = 15
      EditLabel.Caption = #1042#1088#1077#1084#1103
      EditLabel.Font.Charset = RUSSIAN_CHARSET
      EditLabel.Font.Color = clBlue
      EditLabel.Font.Height = -13
      EditLabel.Font.Name = 'Times New Roman'
      EditLabel.Font.Style = []
      EditLabel.ParentFont = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      LabelPosition = lpAbove
      LabelSpacing = 3
      ParentFont = False
      TabOrder = 1
      OnDblClick = LE2DblClick
    end
    object LE3: TLabeledEdit
      Left = 184
      Top = 24
      Width = 502
      Height = 23
      Anchors = [akLeft, akTop, akRight]
      EditLabel.Width = 33
      EditLabel.Height = 15
      EditLabel.Caption = #1058#1077#1082#1089#1090
      EditLabel.Font.Charset = RUSSIAN_CHARSET
      EditLabel.Font.Color = clBlue
      EditLabel.Font.Height = -13
      EditLabel.Font.Name = 'Times New Roman'
      EditLabel.Font.Style = [fsBold]
      EditLabel.ParentFont = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      LabelPosition = lpAbove
      LabelSpacing = 3
      ParentFont = False
      TabOrder = 2
    end
    object Button1: TButton
      Left = 701
      Top = 24
      Width = 81
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      TabOrder = 3
      OnClick = Button1Click
    end
    object LB1: TListBox
      Left = 16
      Top = 64
      Width = 767
      Height = 168
      Anchors = [akLeft, akTop, akRight, akBottom]
      Font.Charset = ANSI_CHARSET
      Font.Color = clRed
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ItemHeight = 15
      ParentFont = False
      PopupMenu = PopupMenu1
      Sorted = True
      TabOrder = 4
      OnDblClick = LB1DblClick
    end
  end
  object Timer1: TTimer
    Interval = 30000
    OnTimer = Timer1Timer
    Left = 16
    Top = 8
  end
  object TI1: TTrayIcon
    Hide = True
    RestoreOn = imDoubleClick
    PopupMenuOn = imNone
    OnMinimize = TI1Minimize
    OnRestore = TI1Restore
    Left = 48
    Top = 8
  end
  object PopupMenu1: TPopupMenu
    Left = 80
    Top = 8
    object Ht1: TMenuItem
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
      OnClick = Ht1Click
    end
    object N1: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100
      OnClick = N1Click
    end
  end
end
