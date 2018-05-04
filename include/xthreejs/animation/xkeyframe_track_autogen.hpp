#ifndef XTHREE_KEYFRAME_TRACK_HPP
#define XTHREE_KEYFRAME_TRACK_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // keyframe_track declaration
    //

    template<class D>
    class xkeyframe_track : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, name, "");
        XPROPERTY(buffer_type, derived_type, times);
        XPROPERTY(buffer_type, derived_type, values);
        XPROPERTY(std::string, derived_type, interpolation, "InterpolateLinear", xenums::InterpolationModes);

        const std::vector<xw::xjson_path_type>& buffer_paths() const;

    protected:

        xkeyframe_track();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using keyframe_track = xw::xmaterialize<xkeyframe_track>;

    using keyframe_track_generator = xw::xgenerator<xkeyframe_track>;

    //
    // keyframe_track implementation
    //

    //
    // buffer_attribute implementation
    //

    template <class D>
    inline const std::vector<xw::xjson_path_type>&  xkeyframe_track<D>::buffer_paths() const
    {
        static const std::vector<xw::xjson_path_type> default_buffer_paths = { 
            { "times", "buffer" },
            { "values", "buffer" },
        };
        return default_buffer_paths;
    }

    inline void set_patch_from_property(const decltype(keyframe_track::times)& property,
                                        xeus::xjson& patch,
                                        xeus::buffer_sequence& buffers)
    {
        xeus::xjson j = {
            {"shape", property().shape()},
            {"dtype", "float32"},
            {"buffer", xw::xbuffer_reference_prefix() + std::to_string(buffers.size())}
        };
        patch[property.name()] = std::move(j);
        // TODO raw_data -> data upon release 0.16 for xtensor
        buffers.emplace_back(property().raw_data(), 4 * property().size());
    }

    inline void set_property_from_patch(decltype(keyframe_track::times)& property,
                                        const xeus::xjson& patch,
                                        const xeus::buffer_sequence& buffers)
    {
        using value_type = typename decltype(keyframe_track::times)::value_type;
        std::size_t index = xw::buffer_index(patch[property.name()].template get<std::string>());
        const auto& buffer = buffers[index];
        property = xt::adapt(const_cast<float*>(static_cast<const float*>(buffer.data())),
                             buffer.size() / 4, xt::no_ownership(),
                             std::array<std::size_t, 1>{2});
    }
    
    inline void set_patch_from_property(const decltype(keyframe_track_generator::times)& property,
                                        xeus::xjson& patch,
                                        xeus::buffer_sequence& buffers)
    {
        xeus::xjson j = {
            {"shape", property().shape()},
            {"dtype", "float32"},
            {"buffer", xw::xbuffer_reference_prefix() + std::to_string(buffers.size())}
        };
        patch[property.name()] = std::move(j);
        // TODO raw_data -> data upon release 0.16 for xtensor
        buffers.emplace_back(property().raw_data(), 4 * property().size());
    }

    inline void set_property_from_patch(decltype(keyframe_track_generator::times)& property,
                                        const xeus::xjson& patch,
                                        const xeus::buffer_sequence& buffers)
    {
        using value_type = typename decltype(keyframe_track_generator::times)::value_type;
        std::size_t index = xw::buffer_index(patch[property.name()].template get<std::string>());
        const auto& buffer = buffers[index];
        property = xt::adapt(const_cast<float*>(static_cast<const float*>(buffer.data())),
                             buffer.size() / 4, xt::no_ownership(),
                             std::array<std::size_t, 1>{2});
    }
    inline void set_patch_from_property(const decltype(keyframe_track::values)& property,
                                        xeus::xjson& patch,
                                        xeus::buffer_sequence& buffers)
    {
        xeus::xjson j = {
            {"shape", property().shape()},
            {"dtype", "float32"},
            {"buffer", xw::xbuffer_reference_prefix() + std::to_string(buffers.size())}
        };
        patch[property.name()] = std::move(j);
        // TODO raw_data -> data upon release 0.16 for xtensor
        buffers.emplace_back(property().raw_data(), 4 * property().size());
    }

    inline void set_property_from_patch(decltype(keyframe_track::values)& property,
                                        const xeus::xjson& patch,
                                        const xeus::buffer_sequence& buffers)
    {
        using value_type = typename decltype(keyframe_track::values)::value_type;
        std::size_t index = xw::buffer_index(patch[property.name()].template get<std::string>());
        const auto& buffer = buffers[index];
        property = xt::adapt(const_cast<float*>(static_cast<const float*>(buffer.data())),
                             buffer.size() / 4, xt::no_ownership(),
                             std::array<std::size_t, 1>{2});
    }
    
    inline void set_patch_from_property(const decltype(keyframe_track_generator::values)& property,
                                        xeus::xjson& patch,
                                        xeus::buffer_sequence& buffers)
    {
        xeus::xjson j = {
            {"shape", property().shape()},
            {"dtype", "float32"},
            {"buffer", xw::xbuffer_reference_prefix() + std::to_string(buffers.size())}
        };
        patch[property.name()] = std::move(j);
        // TODO raw_data -> data upon release 0.16 for xtensor
        buffers.emplace_back(property().raw_data(), 4 * property().size());
    }

    inline void set_property_from_patch(decltype(keyframe_track_generator::values)& property,
                                        const xeus::xjson& patch,
                                        const xeus::buffer_sequence& buffers)
    {
        using value_type = typename decltype(keyframe_track_generator::values)::value_type;
        std::size_t index = xw::buffer_index(patch[property.name()].template get<std::string>());
        const auto& buffer = buffers[index];
        property = xt::adapt(const_cast<float*>(static_cast<const float*>(buffer.data())),
                             buffer.size() / 4, xt::no_ownership(),
                             std::array<std::size_t, 1>{2});
    }

    template <class D>
    inline void xkeyframe_track<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(name, state, buffers);
        set_patch_from_property(times, state, buffers);
        set_patch_from_property(values, state, buffers);
        xw::set_patch_from_property(interpolation, state, buffers);
    }

    template <class D>
    inline void xkeyframe_track<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(name, patch, buffers);
        set_property_from_patch(times, patch, buffers);
        set_property_from_patch(values, patch, buffers);
        xw::set_property_from_patch(interpolation, patch, buffers);
    }

    template <class D>
    inline xkeyframe_track<D>::xkeyframe_track()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xkeyframe_track<D>::set_defaults()
    {
        this->_model_name() = "KeyframeTrackModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xkeyframe_track));
//}
#endif