object Form2: TForm2
  Left = 611
  Top = 832
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Alarm'
  ClientHeight = 149
  ClientWidth = 571
  Color = clBackground
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    571
    149)
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 16
    Top = 16
    Width = 539
    Height = 117
    Anchors = [akLeft, akTop, akRight, akBottom]
    Color = clYellow
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clRed
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    DesignSize = (
      539
      117)
    object Label3: TLabel
      Left = 1
      Top = 47
      Width = 537
      Height = 26
      Align = alCustom
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Caption = 'Message'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clRed
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      OnDblClick = Label3DblClick
    end
    object BitBtn1: TBitBtn
      Left = 16
      Top = 80
      Width = 105
      Height = 25
      Anchors = [akLeft, akBottom]
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clGreen
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TabStop = False
      OnClick = BitBtn1Click
      Kind = bkOK
    end
    object BitBtn2: TBitBtn
      Left = 418
      Top = 80
      Width = 105
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = #1055#1077#1088#1077#1085#1077#1089#1090#1080
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      TabStop = False
      OnClick = BitBtn2Click
      Kind = bkRetry
    end
    object Edit1: TEdit
      Left = 240
      Top = 8
      Width = 57
      Height = 17
      TabStop = False
      AutoSize = False
      BorderStyle = bsNone
      Color = clYellow
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Text = '17.08.2017'
    end
    object Edit2: TEdit
      Left = 244
      Top = 24
      Width = 49
      Height = 25
      TabStop = False
      BorderStyle = bsNone
      Color = clYellow
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Text = '22:00'
    end
  end
end
