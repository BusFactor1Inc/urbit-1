recl = React.createClass
{div,br,input,textarea} = React.DOM

MessageActions  = require '../actions/MessageActions.coffee'
MessageStore    = require '../stores/MessageStore.coffee'
StationActions  = require '../actions/StationActions.coffee'
StationStore    = require '../stores/StationStore.coffee'
Member          = require './MemberComponent.coffee'

module.exports = recl
  set: ->
    if window.localStorage and @$writing then window.localStorage.setItem 'writing', @$writing.text()

  get: ->
    if window.localStorage then window.localStorage.getItem 'writing'

  stateFromStore: -> 
    s =
      audi:StationStore.getAudience()
      ludi:MessageStore.getLastAudience()
      config:StationStore.getConfigs()
      members:StationStore.getMembers()
      typing:StationStore.getTyping()
      valid:StationStore.getValidAudience()
    s.audi = _.without s.audi, window.util.mainStationPath window.urb.user
    s.ludi = _.without s.ludi, window.util.mainStationPath window.urb.user
    s

  getInitialState: -> @stateFromStore()

  typing: (state) ->
    if @state.typing[@state.station] isnt state
      StationActions.setTyping @state.station,state

  _blur: -> 
    @$writing.text @$writing.text()
    MessageActions.setTyping false
    @typing false

  _focus: -> 
    MessageActions.setTyping true
    @typing true

  addCC: (audi) ->
    listening = @state.config[window.util.mainStation(window.urb.user)].sources
    cc = false
    for s in audi
      if listening.indexOf(s) is -1
        cc = true
    if listening.length is 0 then cc = true
    if cc is true
      audi.push window.util.mainStationPath(window.urb.user)
    audi

  sendMessage: ->
    if @_validateAudi() is false
      $('#audi').focus()
      return
    if @state.audi.length is 0 and $('#audi').text().trim().length > 0
      audi = if @_setAudi() then @_setAudi() else @state.ludi
    else
      audi = @state.audi    
    audi = @addCC audi
    MessageActions.sendMessage @$writing.text().trim(),audi
    @$length.text "0/62"
    @$writing.text('')
    @set()
    @typing false

  _audiKeyDown: (e) ->
    if e.keyCode is 13 
      e.preventDefault()
      setTimeout () ->
          $('#writing').focus()
        ,0
      return false

  _writingKeyUp: (e) ->
    if not window.urb.util.isURL @$writing.text()
      @$length.toggleClass('valid-false',(@$writing.text().length > 62))
    # r = window.getSelection().getRangeAt(0).cloneRange()
    # @$writing.text @$writing.text()
    # setTimeout => 
    #     s = window.getSelection()
    #     s.removeAllRanges()
    #     s.addRange r
    #     console.log r
    #   ,0

  _writingKeyDown: (e) ->
    if e.keyCode is 13
      txt = @$writing.text()
      e.preventDefault()
      if ( (txt.length > 0 and txt.length < 63) or
           window.urb.util.isURL @$writing.text() )
        @sendMessage()
      return false
    @_input()
    @set()

  _input: (e) ->
    text   = @$writing.text()
    length = text.length
    # geturl = new RegExp [
    #  '(^|[ \t\r\n])((ftp|http|https|gopher|mailto|'
    #     'news|nntp|telnet|wais|file|prospero|aim|webcal'
    #  '):(([A-Za-z0-9$_.+!*(),;/?:@&~=-])|%[A-Fa-f0-9]{2}){2,}'
    #  '(#([a-zA-Z0-9][a-zA-Z0-9$_.+!*(),;/?:@&~=%-]*))?'
    #  '([A-Za-z0-9$_+!*();/?:~-]))'
    #                      ].join() , "g"
    # urls = text.match(geturl)
    # if urls isnt null and urls.length > 0
    #   for url in urls
    #     length -= url.length
    #     length += 10
    @$length.text "#{length}/62"

  _setFocus: -> @$writing.focus()

  _validateAudiPart: (a) ->
    # if a[0] isnt "~"
    #   return false
    if a.indexOf("/") isnt -1
      _a = a.split("/")
      if _a[1].length is 0
        return false
      ship = _a[0]
    else
      ship = a
    if ship.length < 3
      return false
    return true

  _validateAudi: ->
    v = $('#audi').text()
    v = v.trim()
    if v.length is 0 
      return true
    if v.length < 5 # zod/a is shortest
      return false
    v = v.split " "
    for a in v
      a = a.trim()
      valid = @_validateAudiPart(a)
    valid

  _setAudi: ->
    valid = @_validateAudi()
    StationActions.setValidAudience valid
    if valid is true
      v = $('#audi').text()
      if v.length is 0 then v = window.util.mainStationPath window.urb.user
      v = v.split " "
      for k,_v of v
        if _v[0] isnt "~" then v[k] = "~#{_v}"
      StationActions.setAudience v
      v
    else
      false

  getTime: ->
    d = new Date()
    seconds = d.getSeconds()
    if seconds < 10
      seconds = "0" + seconds
    "~"+d.getHours() + "." + d.getMinutes() + "." + seconds

  cursorAtEnd: ->
    range = document.createRange()
    range.selectNodeContents @$writing[0]
    range.collapse(false)
    selection = window.getSelection()
    selection.removeAllRanges()
    selection.addRange(range)

  componentDidMount: ->
    window.util.sendMessage = @sendMessage
    StationStore.addChangeListener @_onChangeStore
    MessageStore.addChangeListener @_onChangeStore
    @$el = $ @getDOMNode()
    @$length = $('#length')
    @$writing = $('#writing')
    @$writing.focus()
    if @get() 
      @$writing.text @get()
      @_input()
    @interval = setInterval =>
        @$el.find('.time').text @getTime()
      , 1000

  componentWillUnmount: ->
    StationStore.removeChangeListener @_onChangeStore
    clearInterval @interval

  _onChangeStore: -> @setState @stateFromStore()

  render: ->
    user = "~"+window.urb.user
    iden = StationStore.getMember(user)
    ship = if iden then iden.ship else user
    name = if iden then iden.name else ""

    audi = if @state.audi.length is 0 then @state.ludi else @state.audi
    audi = window.util.clipAudi audi
    for k,v of audi
      audi[k] = v.slice(1)

    k = "writing"

    div {className:k}, [
      (div {className:"attr"}, [
        (React.createElement Member, iden)
        (div {
          id:"audi"
          className:"audi valid-#{@state.valid}"
          contentEditable:true
          onKeyDown: @_audiKeyDown
          onBlur:@_setAudi
          }, audi.join(" "))
        (div {className:"time"}, @getTime())        
      ])
      (div {
          id:"writing"
          contentEditable:true
          onFocus: @_focus
          onBlur: @_blur
          onInput: @_input
          onPaste: @_input
          onKeyDown: @_writingKeyDown
          onKeyUp: @_writingKeyUp
          onFocus: @cursorAtEnd
        }, "")
      div {id:"length"}, "0/62"
      ]
