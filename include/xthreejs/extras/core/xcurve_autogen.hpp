#ifndef XTHREE_CURVE_HPP
#define XTHREE_CURVE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"
#include "../../base/xrender.hpp"

namespace xthree
{
    //
    // curve declaration
    //

    template<class D>
    class xcurve : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xcurve();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using curve = xw::xmaterialize<xcurve>;

    using curve_generator = xw::xgenerator<xcurve>;

    //
    // curve implementation
    //


    template <class D>
    inline void xcurve<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xcurve<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xcurve<D>::xcurve()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcurve<D>::set_defaults()
    {
        this->_model_name() = "CurveModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xcurve>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xcurve>;
        extern template xw::xmaterialize<xthree::xcurve>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xcurve>>;
        extern template class xw::xgenerator<xthree::xcurve>;
        extern template xw::xgenerator<xthree::xcurve>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xcurve>>;
    #endif
#endif

#endif