object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1054#1073#1088#1072#1073#1086#1090#1095#1080#1082' CSV'
  ClientHeight = 473
  ClientWidth = 774
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 201
    Top = 406
    Width = 38
    Height = 13
    Caption = #1055#1077#1088#1080#1086#1076
  end
  object Label2: TLabel
    Left = 223
    Top = 433
    Width = 16
    Height = 13
    Caption = 'k ='
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 8
    Width = 320
    Height = 361
    ColCount = 4
    FixedCols = 0
    RowCount = 2
    TabOrder = 0
  end
  object Button1: TButton
    Left = 8
    Top = 375
    Width = 145
    Height = 25
    Caption = #1048#1085#1074#1077#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1079#1085#1072#1095#1077#1085#1080#1103
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 176
    Top = 375
    Width = 152
    Height = 25
    Caption = #1055#1086#1083#1091#1095#1080#1090#1100' '#1082#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1099
    TabOrder = 2
    OnClick = Button2Click
  end
  object StringGrid2: TStringGrid
    Left = 360
    Top = 8
    Width = 353
    Height = 361
    ColCount = 4
    FixedCols = 0
    RowCount = 11
    TabOrder = 3
    ColWidths = (
      48
      98
      98
      102)
  end
  object Edit1: TEdit
    Left = 256
    Top = 403
    Width = 41
    Height = 21
    TabOrder = 4
    Text = '490'
  end
  object Edit2: TEdit
    Left = 256
    Top = 430
    Width = 41
    Height = 21
    TabOrder = 5
    Text = '180'
  end
  object Button3: TButton
    Left = 360
    Top = 375
    Width = 137
    Height = 25
    Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1084#1086#1076#1091#1083#1080' '#1040#1063#1061
    TabOrder = 6
    OnClick = Button3Click
  end
  object OpenDialog1: TOpenDialog
    Filter = 'CSV File|*.csv'
    Left = 16
    Top = 408
  end
  object SaveDialog1: TSaveDialog
    Filter = 'CSV File|*.csv'
    Left = 48
    Top = 408
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 440
    object File1: TMenuItem
      Caption = 'File'
      object Open1: TMenuItem
        Caption = 'Open'
        OnClick = Open1Click
      end
      object Save1: TMenuItem
        Caption = 'Save'
        OnClick = Save1Click
      end
      object Close1: TMenuItem
        Caption = 'Close'
        OnClick = Close1Click
      end
    end
    object Edir1: TMenuItem
      Caption = 'Edit'
      object Clear1: TMenuItem
        Caption = 'Clear'
        OnClick = Clear1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      OnClick = Help1Click
    end
  end
end
