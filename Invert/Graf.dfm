object Form3: TForm3
  Left = 0
  Top = 0
  Caption = #1043#1088#1072#1092#1080#1082#1080
  ClientHeight = 496
  ClientWidth = 686
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Chart1: TChart
    Left = 8
    Top = 8
    Width = 670
    Height = 217
    Legend.Visible = False
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1082' '#1082#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1086#1074' '#1088#1103#1076#1072)
    View3D = False
    TabOrder = 0
    object Series1: TBarSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.Visible = True
      Gradient.Direction = gdTopBottom
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object Chart2: TChart
    Left = 8
    Top = 238
    Width = 670
    Height = 250
    Legend.Visible = False
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1082' '#1074#1086#1089#1090#1072#1085#1086#1074#1083#1077#1085#1085#1086#1075#1086' '#1089#1080#1075#1085#1072#1083#1072)
    BottomAxis.Grid.ZPosition = 2.000000000000000000
    DepthAxis.Automatic = False
    DepthAxis.AutomaticMaximum = False
    DepthAxis.AutomaticMinimum = False
    DepthAxis.Maximum = 1.160000000000001000
    DepthAxis.Minimum = 0.160000000000000300
    DepthTopAxis.Automatic = False
    DepthTopAxis.AutomaticMaximum = False
    DepthTopAxis.AutomaticMinimum = False
    DepthTopAxis.Maximum = 1.160000000000001000
    DepthTopAxis.Minimum = 0.160000000000000300
    RightAxis.Automatic = False
    RightAxis.AutomaticMaximum = False
    RightAxis.AutomaticMinimum = False
    View3D = False
    TabOrder = 1
    PrintMargins = (
      15
      41
      15
      41)
    object Series2: TLineSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.Visible = False
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series3: TPointSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.Visible = False
      ClickableLine = False
      Pointer.HorizSize = 1
      Pointer.InflateMargins = True
      Pointer.Style = psCircle
      Pointer.VertSize = 1
      Pointer.Visible = True
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
end
